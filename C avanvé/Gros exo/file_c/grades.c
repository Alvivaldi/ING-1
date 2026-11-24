#include "grades.h"
#include <stdlib.h>

int init_grades(Grades* grades){
    if(grades==NULL){
        return -1;
    }
    grades->values=NULL;
    grades->size=0;
    return 0;
        
}

void destroy_grades(Grades* grades){
    if(grades==NULL){
        return;
    }

    free(grades->values);
    //free uniquement sur truc crée par malloc
    grades->values=NULL;
    grades->size=0;
    
    return;
        
}

int add_grade(Grades* grades,float value){
    if (grades==NULL){
        return -1;
    }
    //on ajoute note donc on a besoin de plus de taille en mémoire, realloc on donne endroit ou on veux mémoire, taille total
    //realloc libère ancien espace mémoire donc pas besoin de free
    float *tmp=realloc(grades->values,(grades->size+1)*sizeof(float));
    if (tmp==NULL){
        return -1;
    }
    //on change adresse de notre tableau de valeur 
    grades->values=tmp;
    //si size =1 = 1 élément mais vu que ça commence a 0 le size et le numéro de la case d'après, celle que on vient d'allouer
    grades->values[grades->size]=value;
    grades->size++;
    return 0;
}
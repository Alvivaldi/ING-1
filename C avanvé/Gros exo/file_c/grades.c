#include "grades.h"
#include <stdlib>

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
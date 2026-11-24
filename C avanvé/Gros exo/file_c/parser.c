/**
 * @file parser.c
 * @brief Implementation of data.txt parsing functions.
 */


#include "parser.h"

#include <stdio.h>
#include<string.h>

//on crée fonction pour lecture des 3 types de lignes différentes


//pour metre en mémoire il faut mettre étudiant dans class
int parse_student(char* line, Class* promo){
    if (line == NULL || promo == NULL) {
        return -1;
    }
    //c'est la que on crée les variable 
    int id,age;
    char fname[100];
    char lname[100];

//sscabf=scanf mais chaine d ecaractère en mémoire (line)

//lit de gauche a droite :%d, lit entier et le stock dabs id
//  avec ; il vérifie si le caractère suivant est bien ;, si oui il le saute, si non stop
// %99[^;] = scanset % pour dire donnée, 99 =  sécu anti débordement, on laisse 1 pour '\0',[^;] = on lit tout les caractère jusqu'a ;, alors que un simple %s s'arette a espace 
//ça ajoute '\0' tout seul

//fname et lname sont des tableau = pointeur 

//renvoi nb de variable rempli, 4 = tout bon
    if (sscanf(line,"%d;%99[^;];%99[^;];%d",&id,fname,lname,&age)!=4){
        return -1;
    }

    //on a remplit toute nos var,
    return add_student_to_class(promo,id,fname,lname,age);

}


int parse_course_line( char *line, Class *promo) {
    if (line == NULL || promo == NULL) {
        return -1;
    }
    char name[100];
    float coef;
    if(sscanf(line,"%99[^;];%f",name,&coef)!=2){
        return -1;
    }
    //on ajoute cette matière a chaque étudiant dans la promo
    for (int i=0;i<promo->nb_students;i++){
        if (add_course_to_student(&promo->students[i],name, coef)!=0){
            return -1;
        }
    }
    return 0;


}




int parse_grade_line(const char *line, Class *promo){
    if (line == NULL || promo == NULL) {
        return -1;
    }
    int id;
    char class_name[100];
    float grade;

    if(sscanf(line,"%d;%99[^;];%f",&id,class_name,&grade)!=3){
        return -1;
    }
    Student *student = find_student(promo, id);
    if (student == NULL) {
        return -1;
    }

    Course *course = find_course(student, class_name);
    if (course == NULL) {
        return -1;
    }

    if (add_grade_to_course(course, grade) != 0) {
        return -1;
    }

    update_student_avg(student);
    return 0;
}

//création machine a état pour pouvoir appelé les bonnes fonction en fcontion du type de ligne 

typedef enum {
    SECTION_NONE,
    SECTION_STUDENTS,
    SECTION_COURSES,
    SECTION_GRADES
} Section;

//va charger fichier txt dans mémoire
//const char* par ce que fopen attend const char*
int load_class(const char* filepath,Class *promo){
    if (filepath == NULL || promo == NULL) {
        printf("impossible ouvrire fichier");
        return -1;
    }
    //création pointeur vers un flux (retient ou est pointeur)
    //r pour read
    FILE* file=fopen(filepath,"r");

    if (file==NULL){
        return -1;
    }

    //on crée buffer temporaire qui va contenir chaque lignr
    char line[256];
    //on crée état de type sectio, et on le def a none (début)
    Section current_section=SECTION_NONE;
    //permet de sauter une la ligne info de la section
    int skip_header=0;
    //line = endroit ou s'ecrit ligne, taille maximal buffer donc 256 sizeof line
    //file est le flux dans lequelle il doit lire
    //a chaque début de boucle, line est la ligne suivante, jusqu'a fin du fichier
    while(fgets(line,sizeof(line),file)!=NULL){
//netoyage de la ligne, car la ligne contient a la fin \r\n\0 pour retour a la ligne
    
//string complementary span compte combien de caractère avant de tomber sur \r ou \n    
//donc a cette endroit la, on remplace par fin de ligne 


        line[strcspn(line,"\r\n")]='\0';
        //ignorer ligne vide
        if (line[0]=='\0'){
            //continue interomp/renvoie au début de la boucle = fin analise de la ligne
            continue;
        }

        //detect changement section
        //strcmp comparé 2 chaines caractère
        if(strcmp(line,"ETUDIANTS")==0){
            current_section=SECTION_STUDENTS;
            //prochaine ligne on skip le header
            skip_header=1;
            continue;
        }
        if (strcmp(line, "MATIERES") == 0) {
            current_section = SECTION_COURSES;
            skip_header = 1;
            continue;
        }
        if (strcmp(line, "NOTES") == 0) {
            current_section = SECTION_GRADES;
            skip_header = 1;
            continue;
        }

        if(skip_header){
            skip_header=0;
            continue;
        }

        //res nous dira si il y a eu un problème ou pas
        int res=0;
        //on fait un switch case pour donner la ligne a la bonne fonction
        switch (current_section){
            case SECTION_STUDENTS:
                res = parse_student(line,promo);
                //break pour sortir du switch case
                break;
            case SECTION_COURSES:
                res = parse_course_line(line, promo);
                break;
            case SECTION_GRADES:
                res = parse_grade_line(line, promo);
                break;
            //si aucun des cas
            default:
                break;
        }

        //si probleme dans une ligne
        if (res!=0){
            fclose(file);
            return -1;
        }

    }

    fclose(file);
    return 0;


}
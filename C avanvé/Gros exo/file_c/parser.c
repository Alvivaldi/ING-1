/**
 * @file parser.c
 * @brief Implementation of data.txt parsing functions.
 */


#include "parser.h"
#include <stdio.h>

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
    if (sscanf(line,"%d;%99[^;];99[^;];%d",&id,fname,lname,&age)!=4){
        return -1;
    }

    //on a remplit toute nos var,
    return add_student_to_class(promo,id,fname,lname,age);

}


int parse_course_line( char *line, Class *promo) {
    if (line == NULL || promo == NULL) {
        return -1;
    }
    char name[100]:
    float coef;
    if(sscanf(line,"%99[^;];%f",name,&coef)!=2){
        return -1
    }
    //on ajoute cette matière a chaque étudiant dans la promo
    for (int i=0;i<promo->nb_students;i++){
        if (add_course_to_student(promo->students[i],name, coef)!=0){
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

    Course *course = find_course(student, course_name);
    if (course == NULL) {
        return -1;
    }

    if (add_grade_to_course(course, grade) != 0) {
        return -1;
    }

    update_student_avg(student);
    return 0;
}

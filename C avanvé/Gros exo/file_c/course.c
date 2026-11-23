#include "course.h"
#include<stdlib.h>
#include <string.h>
int init_course(Course *course,char *name, float coef) {
    if (course == NULL || name == NULL || coef <= 0.0f) {
        return -1;
    }

    //on fait init de grades avec fonction avant, on donne adresse de grades de ce cours
    if (init_grades(&course->grades) != 0) {
            return -1;
        }

    //def taille de name, +1 pour le '\0'
    course->name=malloc( (strlen(name)+1)*sizeof(char));
    if (course->name==NULL){
        return -1;
    }

    //strcpy copie parametre 2 dans parametre 1
    strcpy(course->name,name);
    course->coef=coef;
    course->avg=0.0;
    return 0;
}

void destroy_course(Course *course){
    if (course==NULL){
        return;
    }
    //on détruit note avec fonction faite avant
    destroy_grades(&course->grades);
    free(course->name);
    course->coef=0;
    course->avg=0.0;
}


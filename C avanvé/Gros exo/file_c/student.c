/**
 * @file student.c
 * @brief Constructor and destructor for Student.
 */

#include "student.h"
#include <stdlib.h>
#include <string.h>

int init_student(Student *student, int id, const char *fname, const char *lname, int age) {
    if (student == NULL || fname == NULL || lname == NULL || age < 0) {
        return -1;
    }


    student->fname = malloc((strlen(fname) + 1) * sizeof(char));
    if (student->fname == NULL) {
        return -1;
    }
    strcpy(student->fname, fname);


    student->lname = malloc((strlen(lname) + 1) * sizeof(char));
    if (student->lname == NULL) {
        //il faut enlever ce qui a été allouer avant 

        free(student->fname); 
        student->fname = NULL;
        return -1;
    }
    strcpy(student->lname, lname);

    student->courses = NULL;
    student->size_courses = 0;
    student->id = id;
    student->avg = 0.0;
    student->age = age;

    return 0;
}

void destroy_student(Student *student) {
    if (student == NULL) {
        return;
    }

    // On détruit chaque matière
    for (int i = 0; i < student->size_courses; i++) {
        //on envoi adresse de course
        destroy_course(&student->courses[i]);
    }

   
    free(student->courses);


    free(student->fname);
    free(student->lname);

    student->courses = NULL;
    student->fname = NULL;
    student->lname = NULL;
    student->size_courses = 0;
    student->id = 0;
    student->avg = 0.0;
    student->age = 0;
}


int add_course_to_student(Student* student, char* name, float coef){
    if (student==NULL || name==NULL){
        return -1;
    }
    Course* tmp=realloc(student->courses,(student->size_courses +1)*sizeof(Course));
    if (tmp==NULL){
        return -1;
    }
    student->courses=tmp;
    //Course* = tableau de course de l'édutiant, ici on ajoute nouvelle matiere a tableau de course, on initialise nouvelle matière en donnant l'adresse d'un nouveau course, qu'on a allouer avant 
    if (init_course(&student->courses[student->size_courses],name,coef)!=0){
        return -1;
    }

    student->size_courses++;
    return 0;

}

Course* find_course(Student* student, char* name){
    if (student==NULL || name==NULL){
        return NULL;
    }
    for (int i=0;i<student->size_courses;i++){

        //strcmp pour comparer 2 chaines de caractère 
        if(strcmp(student->courses[i].name,name)==0){
            return &student->courses[i];
        }
    }
    return NULL;
}

int update_student_avg(Student* student){
    if (student==NULL){
        return -1;
    }
    float sum=0;
    float sum_coef=0;
    for(int i=0;i<student->size_courses;i++){
//consigne on prend pas en compte course ou pas éval
        if((student->courses[i].grades.size)>0){
            sum+=(student->courses[i].avg)*student->courses[i].coef;
            sum_coef+=student->courses[i].coef;
        }
        
    }
    if (sum_coef> 0.0f) {
        student->avg = sum / sum_coef;
    } else {
        student->avg = 0.0f;
    }
    return 0;
}
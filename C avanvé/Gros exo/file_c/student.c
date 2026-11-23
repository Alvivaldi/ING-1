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
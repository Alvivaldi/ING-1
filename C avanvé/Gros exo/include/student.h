/**
@file student.h
@brief manage structure student
*/

#ifndef STUDENT_H
#define STUDENT_H


#include "course.h"

/**
@brief Structure with id, first name, last name etc */
typedef struct{
    char* fname;
    char* lname;
    Course* courses;
    int size_courses;
    int id;
    float avg;
    int age;
}Student;


int init_student(Student *student, int id, const char *fname, const char *lname, int age);
void destroy_student(Student *student);

#endif
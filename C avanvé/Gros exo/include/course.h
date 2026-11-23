/**
@file course.h
@brief manage courses
*/

#ifndef COURSE_H
#define COURSE_H

#include<stdio.h>
#include "grade.h"
/**
@brief represent course with grade name coef and average
 */
typedef struct{
    Grades grades; /**<grades of the course */
    char* name;/**<name of the course */
    float coef;/**<  coef of the course */
    float avg;/**<average of the course */

}Course;

int init_course(Course* course, char* name, float coef);
void destroy_course(Course *course);


#endif
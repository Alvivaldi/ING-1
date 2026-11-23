/**
@file grade.h
@brief Structure to manage aray of grades
*/
#ifndef GRADE_H
#define GRADE_H



#include <stdio.h>

/**
@brief Dynamic array of float for grades
*/
typedef struct{
    float* values; /**<Pointer toward the array of grades */
    int size;/**<number of grades stored */
}Grades;

int init_grades(Grades* grades);
void destroy_grades(Grades* grades)

#endif

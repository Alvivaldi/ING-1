#ifndef CLASS_H
#define CLASS_H

#include "student.h"

typedef struct{
    Student* students;
    int nb_students;
}Class;


int init_class(Class* promo);
void destroy_class(Class* promo);


int add_student_to_class(Class* promo,int id, char* fname, char* lname, int age);

Student* find_student(Class* promo, int id);
#endif

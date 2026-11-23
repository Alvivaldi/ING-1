#ifndef CLASS_H
#define CLASS_H

#include "student.h"

typedef struct{
    Student* students;
    int nb_students;
}Class;


int init_class(Class* promo);
void destroy_class(Class* promo);
#endif

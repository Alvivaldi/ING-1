#include"student.h"
#include<stdlib.h>


int init_class(Class* promo){
    if(promo==NULL){
        return -1;
    }
    //initialise vecteur vers tableau de students a null
    promo->students=NULL;
    promo->nb_students=0;
    return 0;


}
void destroy_class(Class* promo){
    if (promo==NULL){
        return;
    }
    //c'est des ; et pas des ,
    for(int i=0;i< promo->nb_students;i++){
        destroy_student(&promo->students[i]);
    }

    free(promo->students);

    promo->students=NULL;
    promo->nb_students=0;
}
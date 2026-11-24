#include"class.h"
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


int add_student_to_class(Class* promo,int id, char* fname, char* lname, int age){
    if (promo == NULL || fname == NULL || lname == NULL || age < 0) {
        return -1;
    }
    //on crée adresse vers nouveau tableau de students qui est trop petit pour ajouter le nouveau, c'est a ce moment la que on réalic
    Student* tmp = realloc(promo->students,(promo->nb_students+1)*sizeof(Student));
    if(tmp==NULL){
        return -1;
    }
    promo->students=tmp;
    if (init_student(&promo->students[promo->nb_students],id, fname, lname,age)!=0){
        return -1;
    }
//ne pas oublier d'augmenter nb student
    promo->nb_students++;
    return 0;
}

Student* find_student(Class* promo, int id){
    if (promo==NULL){
        return NULL;
    }
    for (int i=0;i<promo->nb_students;i++){
        if (promo->students[i].id==id){
            //on return adresse de l'étudiant
            return &promo->students[i];
        }
    }
    return NULL;

}
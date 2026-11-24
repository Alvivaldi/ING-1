#include<stdio.h>
#include"parser.h"
#include"display.h"

int main(){
    Class promo;
    if (init_class(&promo)!=0){
        printf("Erreur initialisation classe");
        return -1;
    }

//test fonction load
    if(load_class("data.txt",&promo)!=0){
        printf("Erreur lors du chargement de data.txt\n");
        destroy_class(&promo);
        return -1;
    }
    printf("Chargement reussi ! Nombre d'etudiants : %d\n", promo.nb_students);

    // On affiche les 3 premiers étudiants pour vérifier
    for (int i = 0; i < 3 && i < promo.nb_students; i++) {
        Student *s = &promo.students[i];
        printf("- [%d] %s %s (%d ans) | %d matieres | Moyenne : %.2f\n",
               s->id, s->fname, s->lname, s->age, s->size_courses, s->avg);
    }


    display_class(&promo);
    destroy_class(&promo);
    return 0;
}


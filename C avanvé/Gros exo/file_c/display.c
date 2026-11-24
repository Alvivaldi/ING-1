#include"display.h"

//fichier servant a afficher des trucs

//une fonction display doit jamais modif un truc donc on dit const au cas où
void display_grades(const Grades* grades){
    if(grades==NULL){
        return;
    }
    if (grades->size == 0) {
        printf("Aucune note");
        return;
    }
    printf("[");
    for (int i=0;i<grades->size;i++){
        printf("%f, ",grades->values[i]);
        //pour faire jolie et pas mettre une virgule a la dérnière
        if (i < grades->size - 1) {
            printf(", ");
    }
    printf("]");
}
}

void display_course(const Course* course){
    printf("Nom de la matière : %s \n  coef de la matière : %f \n moyenne de la matière : %f\n note de la matière : ",course->name,course->coef,course->avg);

    display_grades(&course->grades);
}


void display_student(const Student *student) {
    if (student == NULL) {
        return;
    }

    printf("============================================================\n");
    printf("Etudiant #%d : %s %s (%d ans)\n",
           student->id, student->fname, student->lname, student->age);
    printf("Moyenne generale : %.2f / 20\n", student->avg);
    printf("Matieres (%d) :\n", student->size_courses);

    for (int i = 0; i < student->size_courses; i++) {
        display_course(&student->courses[i]);
    }
}

void display_class(const Class *promo) {
    if (promo == NULL) {
        return;
    }

    printf("================ PROMOTION (%d etudiants) ================\n",
           promo->nb_students);

    for (int i = 0; i < promo->nb_students; i++) {
        display_student(&promo->students[i]);
    }
    printf("============================================================\n");
}
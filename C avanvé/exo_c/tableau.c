/*
CTRL MAJ A
Exercice 1 (Fonctions de base)
1. Définir une constante SIZE dont la valeur est 10.
2. Dans le programme principal, déclarer un taleau d’entiers de taille SIZE.
3. Écrire une procédure printArray qui prends deux arguments :
— Un tableau d’entiers
— Un entier qui correspond à la taille de ce tableau.
Cette procédure doit afficher les éléments du tableau. La tester avec le tableau défini précédement. Qu’obtient-on ?
4. Écrire une procédure fillArray qui prend les même arguments que la procédure printArray. Cette procédure doit
permettre de remplir le tableau avec des valeurs saisies par l’utilisateur.
5. Tester les procédures en remplissant puis affichant le tableau. */


#/*define SIZE 10


void printArray(int* tab,int size){
    printf("voici le tableau : \n");
    for (int i=0;i<size;i++){
        printf("%d\n",tab[i]);
    }
}
int* fillArray(int* tab,int size){
    int val=0;
    for (int i=0;i<size;i++){
        printf("entre valeur : \n");
        scanf("%d",&val);
        tab[i]=val;
    }
    printArray(tab,size);
    return tab;

}

int main(){
    srand(time(NULL));
    int tab[SIZE];
    //printArray(tab,SIZE);
    fillArray(tab,SIZE);
    printf("bonjour");
}    */



/* 
Exercice 2 (Gestion de notes)
Nous allons écrire un programme pour gérer les notes d’une classe de 25 élèves.
1. Définir une constante SIZE de valeur 25.
2. Dans le programme principal, déclarer un tableau de 25 cases qui servira à stocker les notes des étudiants.
3. Récupérer la procédure de l’exercice précédent permettant d’afficher un tableau. La modifier si besoin pour qu’elle
puisse afficher le tableau de cet exercice.
4. Récupérer la procédure fillArray et la modifier si besoin pour qu’elle puisse remplir le tableau avec des valeurs aléa-
toires entre 0 et 20. Rappel : En langage C, on génère des nombres aléatoires avec la fonction rand() qu’il faut initialiser
avec la commande srand( time( NULL ) ). Pour ce faire, il faut inclure les bibliothèques time.h et stdlib.h.
5. Écrire une fonction averageArray(int tab[], int size) qui retourne la moyenne des éléments d’un tableau passé
en paramètre. Tester la fonction en affichant la moyenne de la classe.
6. Écrire une fonction maxArray(int tab[], int size) qui retourne l’élément maximum contenu dans le tableau passé
en paramètre.
7. Écrire une fonction minArray(int tab[], int size) qui retourne l’élément minimum contenu dans le tableau passé
en paramètre.
8. Afficher les valeurs minimum et maximum du tableau de notes.
9. Écrire une fonction searchElmt(int tab[], int size, int elmt) qui parcours le tableau tab et recherche si la
valeur elmt est dans le tableau. Cette fonction retourne -1 si l’élément recherché n’est pas dans le tableau et le numéro
de l’indice où se trouve l’élément s’il est dans le tableau ( si l’élément existe plusieurs fois, on renverra l’indice le plus
petit). Vérifier avec cette fonction si un étudiant a eu la note de 15.
10. Écrire une fonction badMarks(int tab[], int size) qui compte le nombre d’éléments inférieurs à 7 dans le tableau
passé en paramètre. Afficher le nombre de notes inférieures à 7 dans le programme principal. */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 25

void printArray(int* tab,int size){
    printf("voici le tableau : \n");
    for (int i=0;i<size;i++){
        printf("note %d, : %d\n",i+1,tab[i]);
    }
}


void fillArray(int* tab,int size){
    int val=0;
    for (int i=0;i<size;i++){
        
        val=rand()%21;
        tab[i]=val;
    }
    printArray(tab,size);

}

int averageArray(int tab[], int size){
  
    int somme =0;
    for (int i=0;i<size;i++){
        
        somme+=tab[i];
        
    }
    somme=somme/size;
    printf("moyenne = %d \n",somme);
    return somme;

}

int maxArray(int tab[], int size){
    int max =tab[0];
    for (int i=0;i<size;i++){
        if (tab[i]>max){
            max=tab[i];
        }
    }
    printf("max = %d \n",max);
}
int minArray(int tab[], int size){
    int min=tab[0];
    for (int i=0;i<size;i++){
        if (tab[i]<min){
            min=tab[i];
        }
    }
    printf("min = %d \n",min);
}

int searchElmt(int tab[], int size, int elmt){
    
    for (int i=0;i<size;i++){
        if (tab[i]==elmt){
            return i;
        }
    }
    return -1 ;

}
int main(){
    srand(time(NULL));
   
    int tab[SIZE];
    fillArray(tab,SIZE);
    averageArray(tab,SIZE);
    maxArray(tab,SIZE);
    minArray(tab,SIZE);
    printf("%d\n",searchElmt(tab,SIZE,15));

}
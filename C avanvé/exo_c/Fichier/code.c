#include<stdio.h>
#include<stdlib.h>

/*Exercice 1 (Test des fonctions de base)
1. Creer un nouveau fichier texte.txt dans votre répertoire courant. L’ouvrir et écrire "Je suis ton père" dedans.
2. Dans un programme C ouvrir le fichier en mode lecture à l’aide de la fonction fopen.
3. Récupérer et afficher le premier caractère du fichier ouvert grace à la fonction fgetc.
4. Récupérer et afficher la phrase entière écrite dans le fichier ouvert grace à la fonction fgets.
5. Écrire le mot "Luke" en début de fichier grace à la fonction fputs
6. Creer un second fichier chiffre.txt dans votre repertoire courant. L’ouvrir et écrire "42 7 2.5" dedans.
7. Sommez le premier et dernier nombre du fichier à l’aide de la fonction fscanf*/

int main(){
    FILE* fichier=fopen("texte.txt","r+");
    if(fichier==NULL){
        printf("erreur");
    }
    printf("%c\n",fgetc(fichier));
    char phrase[100];
    rewind(fichier);
    fputs("luke, ",fichier);
    rewind(fichier);
    printf("%s\n",fgets(phrase, 100,fichier));

    fclose(fichier);
}
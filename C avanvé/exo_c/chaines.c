/* Exercice 1 (Majuscule / minuscule)
1. Écrire une fonction char toUpper (char c) qui prend en paramètre une lettre minuscule et retourne son équivalent
en majuscule.
2. Écrire une fonction char toLower (char c) qui prend en paramètre une lettre majuscule et retourne son équivalent
en minuscule.
3. Écrire une fonction char changeLetter (char c) qui
— retourne l’équivalent de c en minuscule si c est une majuscule
— retourne l’équivalent de c en majuscule si c est une minuscule
— ne fait rien si le caractère n’est pas une lettre.
4. Dans le programme principal déclarer une chaîne de caractères suffisament grande pour stocker un prénom.
5. Saisir et afficher le prénom saisi.
6. D’après les règles de grammaire, la première lettre d’un prénom doit être une majuscule et les autres lettres des
minuscules. Modifier la chaîne de caractère afin que le prénom saisi respecte ces règles. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*char toUpper (char c){
    char result = c+('A'-'a');
    printf("Voila le résultat : %c\n",result);
    return result;
    
}
char toLower (char c){
    char result = c+('a'-'A');
    printf("Voila le résultat : %c\n",result);
    return result;
    
}
int main(){
    toUpper('b');
    toLower('B');
    char prenom[25];
    printf("entrez prénom \n");
    scanf("%s",prenom);
    printf("voici prénon %s",prenom);
}*/
/*Exercice 2 (Fonctions de bases)
Ne pas oublier de tester ces fonctions !
1. Écrire une fonction getStringSize qui prend en paramètre une chaîne de caractères et retourne sa taille.
2. Écrire une fonction areStringEqual qui prend en paramètre deux chaîne de caractères et qui retourne 1 si les chaînes
sont les mêmes, 0 sinon.
3. Ecrire une fonction concatStrings qui prend en paramètre deux chaînes de caractères qui vont être concaténées (on
va "coller" les chaînes de caractères l’une à la suite de l’autre).*/
int getStringSize(char * s){
    int i=0;
    while(s[i]!='\0'){
        i+=1;
    }    
    return i; 
}
int main(){

    printf("%d",getStringSize("Ceci est un test"));
}
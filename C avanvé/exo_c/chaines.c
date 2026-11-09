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


char toUpper (char c){
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
}
/*Exercice 1 (Un peu de géomètrie)
Un point dans un espace 2D est caractérisé par son abscisse et son ordonnée.
1. Déclarer et définir une structure Point.
2. Ecrire une fonction constructeur_Point() qui retourne un Point dont les attributs ont été saisis par l’utilisateur.
3. Ecrire une procédure affiche_Point( Point x) qui affiche les attributs du Point passés en paramètres sous forme
(abscisse, ordonnée).
4. Dans le programme principal, définir deux variables de type Point. Les définir et les afficher en utilisant les deux
fonctions précédentes.
5. Ecrire une fonction ajouter_Point(Point a, Point b) qui retourne un Point dont les coordonnées sont la somme
des coordonnées des points aet b.
6. Écrire une fonction longueur( Point a, Point b) qui retourne la longueur du segment ab.
Indication : On pourra utiliser sqrt() qui calcule la racine carrée. Cette fonction est dans la bibliothèque math.h. Si
cette bibliothèque est incluse dans le code il faut rajouter -lm à la suite de la ligne de commande de compilation.
7. Écrire une fonction estCarre( Point a, Point b, Point c, Point d) qui retourne 1 si les 4 points passés en pa-
ramètre forment un carré.
8. Écrire une fonction sontAlignes( Point a, Point b, Point c) qui retourne 1 si les trois Points passés en para-
mètres sont alignés (appartiennent à la même droite)*/

#include<stdio.h>


typedef struct{
    float abs;
    float ord;
}Point;


Point constructeur_Point(){
    Point a;
    printf("entrez abs\n");
    scanf("%f",&a.abs);
    printf("entrez ord\n");
    scanf("%f",&a.ord);
   
    printf("%f, %f",a.abs, a.ord);
    return a;
}

int main(){
   constructeur_Point();

}
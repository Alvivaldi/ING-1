#!/bin/bash
a=ls
a=$((15+45+78+15))
echo "$a"
#`pour fonction`

: '
Exercice 2 (Propriétés et comptage des fichiers)
1. Créer un dossier shell et créer plusieurs fichiers à l’intérieur (ils peuvent être vides) :
— p1.c
— p2.pas
— p3.py
— memo
— p4.c
— p5.txt
— p6.sh
— p7.sh
2. Mettre les droits en exécution aux fichiers p3.py, p6.sh et p7.sh
3. Dans le répertoire parent de shell, créer un script find_exec.sh qui doit être appelé avec un seul argument qui
doit obligatoirement être un répertoire.
4. Modifier le script pour qu’il liste tous les fichiers, et affiche ceux qui sont exécutables.
5. modifier le script pour qu’il affiche maintenant la taille des fichiers exécutables.
'
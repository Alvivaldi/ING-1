#!/bin/bash


if [ $# -ne 1 ] || [ ! -d "$1" ]
then
    echo "Attention il faut 1 seul arg et que ça soit un dossier"
    exit 1
fi

for fichier in "$1"/*
    do echo " $fichier"
    if [ -x "$fichier" ]
    then
        echo "il est executable"
        echo `du -h "$fichier"`
    fi
done


: '
Exercice 3 (Traitement des notes)
1. Créer le fichier notes.txt suivant :
Liste des notes CY-TECH : ING1 (2025-2026)
Nom étudiant:note
Paco:10
Pépé:5
José:18
Hermano:15
Pablo:19.5
Luis:2
Toto:20
Titi:7
12. Créer un script qui permet d’afficher le contenu de ce fichier mais avec les lignes triées par notes décroissantes. Les 2
premières lignes doivent être affichées en premier : seules les lignes avec notes doivent être triées.
Le script prendra en paramètre le fichier notes.txt, vérifiera que le fichier existe et que c’est bien un fichier, vérifiera
que le nombres de lignes à l’intérieur du fichier est compatible avec le traitement demandé, et enfin affichera le contenu.
3. Modifier le script pour afficher un message personnalisé si une erreur survient. Ce message devra être envoyé sur l’erreur
standard et non sur la sortie standard.
4. Modifier le script pour retourner un code d’erreur différent pour chaque message précédent. Le script retournera le
code 0 si tout s’est bien passé.ls
'
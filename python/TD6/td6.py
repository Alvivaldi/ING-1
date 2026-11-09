#Exercice 1 (Creation de journal de bord)
"""Ecrire une procédure log_create(filename, force=False) qui va créer un fichier texte servant à stocker des messages
comme un carnet de bord. Cette fonction prend en paramètre le nom du fichier à créer.
— Le fichier doit être créé en mode création exclusive.
— Si le paramètre force est activé, alors la fonction va créer le fichier en mode écriture seule pour forcer l’effacement
du fichier si il existait déjà.
— Cette fonction va écrire une phrase "Journal de bord" pour la toute première ligne du fichier.
— Le flux créé sera fermé à la fin de la fonction."""

import os

print("bonjour")

def log_create(filename, force=False):
    if force:
        mode ="w"
    else:
        mode="x"
    try : 
        with open(filename,mode,encoding="utf-8") as f:
            f.write("Journal de bord")
        print("c'est fait")
    except FileExistsError :
        print("probleme")

log_create("test.txt")




# Récupère le dossier où se trouve ton script actuel
dossier_script = os.path.dirname(os.path.abspath(__file__))

# Crée le chemin complet pour test.txt
chemin_complet = os.path.join(dossier_script, "test.txt")

log_create(chemin_complet)



"""Exercice 2 (Ajout d’une entrée)
Ecrire une procédure log_add_entry(outstream, event) qui va ajouter des messages dans le journal de bord.
Elle prend en paramètre un descripteur de fichier qu’on suppose déjà ouvert en écriture et positionné à la fin du fichier,
ainsi qu’un dictionnaire qui contiendra les informations de l’événement à noter dans le journal.
— L’évènement passé en paramètre est un dictionnaire avec 4 clés :
— ’date’ : une chaîne de caractères au format JJ/MM/AAAA
— ’author’ : une chaîne de caractères indiquant le nom de la personne qui a noté l’évènement dans le journal
— ’message’ : une chaîne de caractères du message
— ’valid’ : un booléen pour indiquer si ce message est toujours valide ou non (on veut se laisser la possibilité de
rayer certains message du journal, mais tout en conservant l’historique)
— La fonction va récupérer ces informations et les écrire dans le fichier avec le formalisme suivant :
[X] <Author> (<Date>)
<message>
[ ] <Author> (<Date>)
<message>
— Le caractère ’X’ indique que le message n’est plus valide (il est barré). Si le message est toujours valide, alors il y
aura un espace à la place.
— Cette fonction ne ferme pas le flux donné en paramètre"""


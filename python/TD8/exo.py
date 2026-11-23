#import ship
#ship.Ship

from ship import Ship


def display_ship(ship):
    print("Voici le bateau nom : ",ship.name,"\n captain : ",ship.captain,"\n speed : ", ship.speed,"\n crew : ",ship.crew,"\n cannons : ",ship.cannons,"\n\n")
    print(ship)
print(Ship)
sh1=Ship()
sh2=Ship()
sh2=Ship()

#display_ship(sh1)


"""Exercice 2 (Mise à l’eau)
1. créer une fonction display_ship(...) qui prend un objet Ship en paramètre et qui affiche tous ses attributs à l’écran.
2. Dans le script principal, importer la classe Ship créée précédemment et l’instancier une fois.
3. A l’aide de print(...), afficher l’objet créé : que remarque-t-on ?
4. A l’aide de display_ship(...), afficher les valeurs de chacun des attributs de l’objet créé.
5. Modifier les valeurs de chaque attribut et réafficher toutes les valeurs pour vérifier les changements."""

def create_ship(name,captain,speed,crew,cannons):
    ship=Ship()
    ship.name=name
    ship.captain=captain
    ship.speed=speed
    ship.crew=crew
    ship.cannons=cannons
    #display_ship(ship)
    return ship

create_ship("le bateau","moi",1000,[],5)



"""Exercice 3 (Flotte fantôme)
1. Instancier plusieurs fois la classe Ship et ajouter tous les objets dans une même liste.
2. Parcourir la liste et mettre à jour les attributs aves des valeurs aléatoires pour les valeurs numériques, et utiliser des
chaînes génériques pour les noms :
— "Ship xx"
— "Captain xx"
— avec xx le numéro du bateau qui s’incrémente
3. Créer une fonction display_fleet(...) qui prend en entrée une liste de Ship et qui va afficher toutes les informations
de tous les bateaux."""

from random import randint


def display_fleet(f):
    for s in f:
        display_ship(s)


def create_n_ship(n):
    liste=[]
    for i in range(n):
        liste.append(create_ship("Ship xx","Captain xx",randint(100,200),[],randint(1,50)))
        
    #display_fleet(liste)
    return(liste)
create_n_ship(5)


"""
Exercice 4 (Un bateau peut en cacher un autre)
1. Créer une fonction copy_ship(...) qui prend 2 objets Ship en paramètre et qui va copier les valeurs de tous les
attributs du premier vers le deuxième.
2. Créer deux variables ship01 et ship02 qui contiennent deux instances distinctes de la classe Ship.
3. Modifier les attributs de ship01 et ship02 avec des valeurs distinces puis les afficher.
4. Créer une variable ship03 et lui affecter le contenu de la variable ship01.
1
5. Afficher les égalités suivantes :
— ship01 == ship02
— ship01 == ship03
Que peut-on observer ?
6. Utiliser la fonction copy_ship(...) pour copier les attributs de ship02 vers ship01.
Réafficher le contenu des 3 objets ainsi que les résultats des égalités précédentes que peut-on observer maintenant ?
7. Afficher les égalités suivantes :
— ship01 is ship02
— ship01 is ship03
Que peut-on observer ?
La différence entre == et is sera détaillée dans un prochain TD
"""

def copy_ship(s1,s2):
    s2.name=s1.name
    s2.captain=s1.captain
    s2.speed= s1.speed
    s2.crew= s1.crew
    s2.cannons= s1.cannons

ship01=create_ship("black","jean",555,[],52)
ship02=create_ship("white","paul",15000,[],2)
"""display_ship(ship01)
display_ship(ship02)

ship03=Ship()
copy_ship(ship01,ship03)

display_ship(ship03)

print(ship01==ship02,ship01==ship03)

copy_ship(ship02,ship01)

display_ship(ship01)
display_ship(ship02)

print(ship01==ship02,ship01==ship03)"""



"""Exercice 5 (Un équipage de choc)
1. Dans un fichier crew.py, créer une classe CrewMember qui va initialiser un objet avec un seul attribut : un nom (str).
2. Dans le script principal, importer cette classe pour pouvoir l’instancier
3. En utilisant la liste members, Créer des CrewMember avec les noms qui sont fournis. Ajouter tous ces objets dans l’at-
tribut crew d’un objet de type Ship.
Quelle différence avec une mise à jour du nom du bateau ?"""
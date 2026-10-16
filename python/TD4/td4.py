from TD04_data import goods as goods_list
from TD04_data import ship_names
# Exercice 1 (La naissance d’une flotte)
# Créer une fonction createFleet(names, default_capacity=1000.0)
# qui va prendre une liste de noms de tous les bateaux à créer et qui va renvoyer un dictionnaire contenant ces bateaux.
# Un paramètre nommé supplémentaire, default_capacity, sera utilisé pour créer le poids maximal que peut porter chaque
# bateau.
# La clé du dictionnaire sera le nom des bateaux, et les valeurs seront des sous-dictionnaires contenant les données suivantes :
# — ’name’ : le nom du bateau dupliqué ici
# — ’dest’ : le nom de la destination. None par défaut
# — ’max_wgt’ : le poids maximal qu’il est capable de transporter. La valeur par défaut est donné via le paramètre nommé
# default_capacity.
# — ’wgt’ : le poids total des marchandises actuellement dans la cale du bateau
# — ’goods’ : une liste contenant les marchandises qui sont dans la cale du bateau

print(goods_list,"\n")

print(ship_names)

def print_fleet(fleet):
    for bateau in fleet:
        print(bateau,"\n",fleet[bateau],"\n")

def createFleet(names, default_capacity=1000.0) :
    dict={}
    for bateau in names:
        dict[bateau]={"name":bateau,"dest":None,"max_wgt":default_capacity,"wgt":0,"goods":[]}
    print_fleet(dict)
    return dict


fleet =createFleet(ship_names)



# Exercice 2 (L’état de la flotte)
# Créer une fonction displayFleet(fleet, show_capacity=True, show_empty=False)
# qui va prendre en argument une flotte entière de bateaux retournée par la fonction précédente et afficher le nom et lme
# nombre de marchandises de chaque bateau.
# Deux paramètres booléens nommés seront ajoutés avec comme rôle :
# — show_capacity : permet d’afficher la capacité maximale du bateau
# — show_empty : permet d’afficher un bateau si il est vide, sinon il n’est pas affiché

def displayShip(ship,show_capmax):
    txt=""
    txt+=ship["name"]+", NB Marchandise : "+str(len(ship["goods"]))
    if show_capmax :
        capmax=ship["max_wgt"]
        txt+= " Capacité max :"+str(capmax)
    print(txt,"\n")



def displayFleet(fleet, show_capacity=True, show_empty=True):
    for ship in fleet:
            
        wgt=fleet[ship]["wgt"]
        if show_empty  and wgt==0:
            displayShip(fleet[ship],show_capacity)
        elif wgt!=0 :
            displayShip(fleet[ship],show_capacity)
            

displayFleet(fleet)


# Exercice 3 (Embarquement des marchandises)
# Créer une fonction load_cargo(ship, cargo, check_weight=True)
# qui va prendre en argument un bateau (dictionnaire), une marchandise (tuple) et qui va charger cette dernière dans la
# cale. Elle retournera un booléen pour indiquer si la marchandise a été correctement stockée dans la cale ou non.
# Si le bateau ne possède pas de destination (’dest’ = None), alors la destination de la marchandise deviendra la nouvelle
# destination du bateau.
# Si le bateau possède une destination, alors on ne chargera la marchandise que si cette dernière possède la même destina-
# tion (le but est de charger un bateau pour une seule destination).
# Un paramètre nommé booléen check_weight servira à indiquer si on doit vérifier que le poids de la nouvelle marchandise
# peut etre ajouté dans le bateau sans surcharge. Si ce paramètre est désactivé, alors on charge sans aucune vérification (et le
# bateau peut entrer en surcharge).

def charge(ship,cargo,poid):
    ship[goods].append(cargo)
    ship["wgt"]+=poid
    return ship

def load_cargo(ship, cargo, check_weight=True):
  
    if ship["dest"] is not None and ship["dest"].lower() != cargo[3].lower():
        return False
        
    poid = cargo[1] * cargo[2]
    

    if check_weight and (ship["wgt"] + poid > ship["max_wgt"]):
        return False
        
  
    charge(ship, cargo, poid)
    
    if ship["dest"] is None:
        ship["dest"] = cargo[3]
        
    return True 

a=0

def fonction(a):
    a=10
print(a)
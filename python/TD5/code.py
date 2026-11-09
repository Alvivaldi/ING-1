from TD05_data import goods

# def f(*arg):
#     print("normal",arg)
#     print(*arg)

# f((1,2,3),1)



# # 1. PACKING : La fonction regroupe les arguments reçus
# def creer_profil(nom, *args, **kwargs):
#     print("Nom principal :", nom)
#     print("Autres infos (Tuple) :", args)
#     print("Détails (Dictionnaire) :", kwargs)
#     print("---")

# # Appel classique : Python "pack" les arguments restants
# creer_profil("Alice", "Développeuse", "Python", age=28, ville="Paris")


# # 2. UNPACKING : On déballe des variables existantes pour les passer à la fonction
# competences = ("DevOps", "Linux")
# options = {"contrat": "CDI", "remote": True}

# # Le * et ** extraient le contenu pour l'injecter dans la fonction
# creer_profil("Bob", *competences, **options)


# Exercice 1 (Baptême en haute mer)
# Ecrire une fonction create_ship(**fields) qui va créer et retourner un dictionnaire représentant un bateau. Utiliser
# pour cela l’empaquetage de paramètres nommés pour chaque champ du bateau.
# Ce dictionnaire doit contenir au minimum les clés ’name’ et ’max_wgt’ contenant respectivement le nom du bateau et
# le poids maximal qu’il peut transporter. Si ces 2 clés ne sont pas passées en paramètre, utiliser l’instruction suivante pour

# stopper le programme et afficher un message d’erreur :
# raise KeyError("...") # indiquer le message d'erreur en paramètre
# Afficher le bateau (dictionnaire) retourné par la fonction pour vérifier le bon fonctionnement. Effectuer plusieurs appels
# avec différents paramètres


def create_ship(**fields):
    if "name" not in fields or "max_vgt" not in fields:
        raise KeyError("manque name or max_vgt")
    return fields


bateau1=create_ship(name="Le bateau",max_vgt=1)
print(bateau1)

# Exercice 2 (Préparer la prochaine expédition)
# Ecrire une fonction add_goods(ship, *goods) qui va ajouter des marchandises dans le bateau. Ce dernier sera passé en
# premier paramètre, et les marchandises seront également passées en paramètres positionnels empaquetés.
# La clé utilisée pour stocker la liste des marchandises dans le bateau doit être présente dans le dictionnaire. Si elle n’est
# pas présente, il faudra la créer.
# La fonction va parcourir tous les paramètres positionnels et les ajouter un à un dans la liste des marchandises du bateau.
# Lors de l’appel à cette fonction, il faudra passer la liste des marchandises récupérées depuis le fichier de données, et pour
# ce faire, il faudra déballer cette liste afin de respecter le prototype.
# Afficher le bateau (dictionnaire) une fois l’ajout de marchandises effectué



def add_goods(ship, *goods):
    if "marchandises" not in ship:
        ship["marchandises"]=[]
    for element in goods:
        ship["marchandises"].append(element)
    print(ship)
    return ship

add_goods(bateau1,goods)


# Exercice 3 (Où est passé ce fichu tonneau ?)
# Créer une fonction find_goods(ship, *values) qui va chercher dans les marchandises du bateau celles qui contiennent
# au moins une des valeurs passées par paramètres positionnels.
# Les valeurs passées peuvent être des chaines de caractères ou des valeurs numériques. La fonction va chercher dans chaque
# champ du tuple marchandise si les valeurs.
# La fonction doit retourner une liste de marchandises qui répondent aux critères en fonction des valeurs passées en
# paramètres. Exemple :
# find_goods(ship, "tea", 'spice', 4)
# — renvoie les marchandises qui contiennent le mot ’tea’ ou ’spice’ dans le nom
# — la casse ne sera pas prise en compte, et une marchandise sera retournée si l’une des valeurs est contenue dans son nom
# (une marchandise avec comme nom ’Spices’ sera retournée si l’une des valeurs vaut ’spice’
# — renvoie toutes les marchandises qui contiennent le nombre 4 dans la quantité ou le poids unitaire


def find_goods(ship, *values):
    pass
from TD07_data import goods
"""
Exercice 1 (Un peu d’empaquetage)
Ecrire une fonction create_entry(...) qui va prendre en argument un empaquetage de paramètres nommés et va re-
tourner le dictionnaire résultant.
Cette fonction va vérifier que les clés suivantes sont présentes et que les types des valeurs associées sont corrects :
— name : le nom de la marchandise (str)
— price : le poids de la marchandise (float)
— quantity : la quantité (int)
— perishable : marchandisse périssable ou non (bool)
Si une des conditions n’est pas respectée, l’Exception TypeError sera levée.
"""




def create_entry(**cargo) :
    fields= ["name","price","quantity","perishable"]
    for field in fields:
        if field not in cargo : 
            msg =f"the fields'{field}'is not in the cargo ! \n"
            msg+=f"Cargo = {cargo}"
            raise TypeError(msg)
    print(cargo)
    return cargo

   
    print(kwargs)

create_entry(name="Rum", quantity=40,price=25.50, perishable=False)


"""
Exercice 2 (Ajout de marchandise)
Ecrire une fonction add_entry(...) qui va prendre comme argument un catalogue, ainsi qu’une marchandise nommée,
dont la valeur par défaut est None.
Cette fonction va ajouter la marchandise passée si elle existe, sinon demander à l’utilisateur de saisir toutes les informa-
tions d’une marchandise pour ensuite l’ajouter.
Dans cette fonction, effectuer les conversions nécessaires à chaque type de donnée de la marchandise.
— Le nom doit contenir au minimum 3 lettres. Il doit être stocké en minuscules avec la première lettre en majuscule,
quelle que soit l’entrée de l’utilisateur.
— Le prix et la quantité doivent être supérieures strictement à 0.
— le booléen doit être entré sous la forme Y/N ou bien YES/NO peu importe la casse. Toute autre entrée est considérée
comme invalide. Cette entrée doit ensuite être convertie en booléen.
1
Si l’une des consignes précédentes n’est pas respectée, l’Exception TypeError doit être levée.
La fonction va rechercher si la marchandise existe déjà (nom) : si c’est le cas, l’Exception ValueError sera levée.
Sinon, utiliser la fonction de la question précédente pour créer la nouvelle marchandise et l’ajouter dans le catalogue.
Dans le programme principal, tester cette fonction et faire en sorte de gérer les Exceptions TypeError et ValueError
avec un affichage explicite ainsi que le détail de l’exception.
Utiliser les instructions suivantes pour afficher le détail de l’exception qui a été récupérée :
(non présentes dans le support de cours à la date de rédaction du TD)
try:
...
except Exception as ex:
...
print(ex)

"""
# (On part du principe que create_entry est définie juste au-dessus)

def add_entry(cat, march=None):
    # 1. Si aucune marchandise n'est fournie, on demande la saisie
    if march is None:
        # --- NOM ---
        name = input("Entrez le nom : ")
        if len(name) < 3:
            raise TypeError("Le nom doit contenir au moins 3 lettres.")
        name = name.capitalize()
        
        # --- PRIX ---
        price = float(input("Entrez le prix : "))
        if price <= 0:
            raise TypeError("Le prix doit être strictement supérieur à 0.")
            
        # --- QUANTITÉ ---
        quantity = int(input("Entrez la quantité : "))
        if quantity <= 0:
            raise TypeError("La quantité doit être strictement supérieure à 0.")
            
        # --- PÉRISSABLE ---
        p_input = input("Périssable (Y/N ou YES/NO) : ").upper() # .upper() rend la saisie insensible à la casse
        if p_input in ['Y', 'YES']:
            perishable = True
        elif p_input in ['N', 'NO']:
            perishable = False
        else:
            raise TypeError("Entrée invalide pour la conservation. Utilisez Y, N, YES ou NO.")
            
        # Création du dictionnaire via la fonction de l'exercice 1
        march = create_entry(name=name, price=price, quantity=quantity, perishable=perishable)

    # 2. Vérification des doublons dans le catalogue (ValueError)
    # (On suppose que 'cat' est une liste de dictionnaires)
    for item in cat:
        if item['name'] == march['name']:
            raise ValueError(f"La marchandise '{march['name']}' existe déjà dans le catalogue.")
            
    # 3. Ajout au catalogue
    cat.append(march)
    print(f"-> Succès : '{march['name']}' a été ajoutée !")


# ==========================================
# PROGRAMME PRINCIPAL (Tests demandés)
# ==========================================

catalogue_test = [] # Création d'un catalogue vide (une liste)

print("--- TEST D'AJOUT ---")
try:
    # On appelle la fonction en lui passant notre liste vide
    add_entry(catalogue_test)
    
except TypeError as ex:
    print(f"Erreur de saisie (TypeError) : {ex}")
    
except ValueError as ex:
    print(f"Erreur de doublon (ValueError) : {ex}")
    
except Exception as ex: # Permet d'attraper les erreurs de conversion (ex: taper des lettres pour le prix)
    print(f"Erreur inattendue (Exception) : {ex}")

print("\nÉtat du catalogue :")
print(catalogue_test)


"""Exercice 5 (The Black Pearl)
Dans cet exercice, nous partirons du principe que l’utilisateur entre toujours le type de données attendu (par exemple :
si un entier est attendu il n’entrera pas de lettres). La vérification et la gestion d’erreurs de conversions seront traitées plus
tard lors du chapitre sur la programmation Objet et les Exceptions.
En tant qu’utilisateur francophone, toutes les valeurs réelles entrées par l’utilisateur devront utiliser le caractère ’,’
(virgule) et non le caractère ’.’ (point). Le programme devra donc pouvoir gérer cette petite subtilité d’interface. Si une
valeur réelle est entrée par l’utilisateur avec un ’.’, le programme affichera un message d’erreur et se stoppera.
Toutes variables de types chaine de caractères qui sont affichées à l’écran devront avoir une Majuscule au début et des
minuscules sur le reste des caractères, même si ce n’est pas comme cela qu’elles sont enregistrées dans la mémoire.
1. Demander à l’utilisateur de saisir le nom d’un navire marchand du 17°siècle (str), son année de construction (int), sa
vitesse maximale (float), et l’information sur son chargement (la marchandise est-elle à bord ou non : bool).
Pour ce dernier point, l’utilisateur pourra répondre à la question avec les options suivantes :
— Y ou YES, peu importe la casse
— N ou NO , peu importe la casse
— toute autre valeur affichera un message d’erreur et stoppera le programme
L’année de construction sera une année du 17°siècle uniquement. Sinon le programme affichera un messager et se
stoppera.
L’utilisateur peut décider de ne rien rentrer pour chacun des champs précédents : il appuiera simplement sur ENTREE
et une valeur par défaut sera utilisée par le programme. Valeurs par défaut à utiliser :
— Nom du bateau : ’Black Pearl’
— Année de construction : 1650
— Vitesse maximale : 11.23 noeuds
— chargement : ’Yes’
Si le bateau possède une cargaison à son bord, on pourra continuer le programme, sinon le programme s’arrêtera clas-
siquement.
2. Demander 3 informations :
— le prix unitaire d’une marchandise qui a été achetée
— le prix unitaire à la vente de cette même marchandise
— la quantité de marchandises à vendre
Si le prix de vente est inférieur strictement au prix d’achat, le programme affichera une erreur et se stoppera.
3. Calculer le gain total de la transaction et calculer le montant de la taxe que devra payer le marchand en fonction de
ses gains :
— gain strictement inférieur à 20 doublons : pas de taxe
— entre 20 et inférieur à 100 doublons : 5% des bénéfices
— entre 100 et inférieur à 500 doublons : 8% des bénéfices
— 500 doublons et au-delà : 13% des bénéfices
Une réduction de 10% la taxe totale sera appliquée si la quantité de produits vendus dépasse 50 unités.
Calculer le gain net après impots.
4. Afficher toutes les valeurs saisies et calculées pour établir une fiche récapitulative de la vente"""
nom_base=’Black Pearl’
date_base=1650
vitesse_max_base=11.23
chargé_base=’Yes’

def testeur_de_bool(var):
    var=var.lower()
    if var=="yes" or "y" or "true":
        return True
    elif var=="no" or "n" or "false":
        return False
    else:
        return None
nom=input("Entrez le nom :\n")
if nom=="":
    nom=nom_base
date_str=input("Entrez année de construction :\n")
if date_str=="":
    date_str=date_base
else:
    try:
        date=int(date_str)
    except ValueError:
        print("pas int valide")

vitesse_max_str=input("Entrez vitesse max(float) :\n").replace(",",".")
if vitesse_max_str=="":
    vitesse_max=vitesse_max_base
    else:
        try:
            vitesse_max=float(vitesse_max_str)
        except ValueError:
            print("pas float valide")
chargé_str=input("est ce que c'est chargé ? ")
if chargé_str=="":
    chargé=testeur_de_bool(chargé_base)
if chargé==None:
    print("chargé pas un bool")
    exit()



print(type(nom),nom.capitalize(),type(date),date,type(vitesse_max),vitesse_max,type(chargé),chargé)

if not chargé:
    exit()

print("bonjour")

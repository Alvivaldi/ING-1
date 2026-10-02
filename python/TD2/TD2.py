from TD02_data import goods
def affiche_liste(liste):
    for i in range (0,len(liste)):
        """print("------------------------------","\n")"""
        print(liste[i],"\n")




def ajout_liste(liste,i,complet):
    if (len(complet)-i<5):
        liste.append(complet[i:])
        return liste
    liste.append(complet[i:i+5:])
    i+=5
    return ajout_liste(liste,i,complet)
   




def cree_liste(goods):
    complet=goods
    i=0
    liste=[]
    print(len(complet))
    liste_final=ajout_liste(liste,i,complet)
    return affiche_liste(liste_final)


#cree_liste(goods)

"""2. On souhaite traiter les marchandises dans un ordre particulier :
 d’abord traiter la moitié de la liste en partant du
début, puis l’autre moitié en partant de la fin de la liste.
Créer une liste qui respecte cet ordre de marchandises"""



def afficher_liste_moitier(source):
    taille=len(source)//2
    mi1=source[1:taille]
    print(mi1,"\n taille de la liste",len(mi1),"\n")
    mi2=source[:taille-1:-1]
    print(mi2,"\n",len(mi2))
    

#afficher_liste_moitier(goods)


"""Exercice 2 (Manifeste de marchandises)
1. Parcourir la liste goods et afficher simplement le contenu de chaque case : quel est le type de données contenues dans
cette liste ?

2. Modifier le programme pour n’afficher que le nom de la marchandise et son origine

3. Modifier le programme pour n’afficher que les lignes de marchandises dont le poids total dépasse 1 Tonne."""


def affiche_liste_tuple(liste):
    for i in range(0,len(liste)):
        print("--------","\n")
        for n in range(0,4):
            print(liste[i][n])

affiche_liste_tuple(goods)



"""2. Modifier le programme pour n’afficher que le nom de la marchandise et son origine"""



def affiche_liste_tuple2(liste):
    for i in range(0,len(liste)):
        print("--------","\n")
        print(liste[i][0])
        print(liste[i][3])

affiche_liste_tuple2(goods)



"""3. Modifier le programme pour n’afficher que les lignes de marchandises dont le poids total dépasse 1 Tonne."""





def affiche_liste_tuple3(liste):
    for i in range(0,len(liste)):


      
        print("--------","\n")
        

affiche_liste_tuple2(goods)
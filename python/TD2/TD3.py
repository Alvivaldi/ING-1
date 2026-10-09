from TD03_data import goods



"""
Exercice 1 (De port en port)
Parcourir la liste de marchandises, et les stocker dans un dictionnaire ’ports’ en les regroupant par destination.
La destination servira de clé, et la valeur associée sera la liste contenant toutes les marchandises pour cette destination.
Dans la marchandise, le nom du port ne doit pas être conservé puisqu’il est maintenant factorisé en clé du dictionnaire.
Une fois le dictionnaire créé, vérifier son contenu en le parcourant et en l’affichant à l’écran.
"""

def print_dict(dict):
    for a in dict:
        print(a,dict[a],"\n")



def trier_marchandise(goods): 
    dict={}
 
    for el in goods : 
        if el[3] not in dict:
            dict[el[3]]=[]
        dict[el[3]].append(el[:3])
    return dict
       



"""
Exercice 2 (Partage du butin)
A partir du dictionnaire ’ports’ précédent, créer 2 nouveaux dictionnaires ’spicy’ et ’classic’ dans lesquels on aura
les destinations qui contiennent des épices, et de l’autre celles qui n’en ont pas.
Une fois les dictionnaires créés, vérifier leurs contenus en les parcourant et en les affichant à l’écran
"""

ports =trier_marchandise(goods)



def separe(dic):
    spices={}
    classic=dic
    for el in dic:
        for good in dic[el]:
            if good[0]=="Spices" :
                if el not in spices:
                    spices[el]=[]
                spices[el].append(good)
                classic[el].remove(good)
    print("voila classqiue \n")
    print_dict(classic)
    print("voila epices\n")
    print_dict(spices)

"""separe(dic)"""

"""
Exercice 3 (Le monde à l’envers)
A partir du dictionnaire ’ports’, créer un autre dictionnaire ’cargos’ qui inverse la convention clé-valeurs.
— le dictionnaire d’origine possède comme clés les noms des ports, et comme valeurs la liste des marchandises.
— On souhaite obtenir un dictionnaire qui comportera comme clés les noms des marchandises, et comme valeurs, des
tuples contenant le nom du port et le reste des informations de la marchandise
Une fois le dictionnaire créé, vérifier son contenu en le parcourant et en l’affichant à l’écran.
"""


def inverse_dict(ports):
    cargo={}
    for el in ports:
            port=el
            for good in ports[port]:
               
                if good[0] not in cargo:
                    cargo[good[0]]=[]
                cargo[good[0]].append((el,good[1],good[2]))
    
    return cargo
                

cargo=inverse_dict(ports)


"""
Exercice 4 (Deux cartes, un même monde)
Les dictionnaires ’ports’ et ’cargos’ contiennent exactemement les mêmes informations, mais classées dfféremment.
On émet l’hypothèse que l’accès à une valeur depuis une clé, dans un dictionnaire, est à temps constant : O(1).
Si l’on cherche à créer un algorithme qui va chercher quels ports contiennent du Cacao, quelles complexités temporelles
obtient-on pour C marchandises (cargos) et P ports avec chacun des dictionnaires ?"""

"""
pour cargo 0(n) n = nb 
pour port, (n*n)
"""

"""
Exercice 5 (Le butin prend le large)
1. Séparer le dictionnaire ’cargos’ en 2 : ’light_ship’ et ’heavy_ship’ qui sont respectivement les cargaisons de 2
bateaux différents. Le premier embarque les marchandises de moins de deux Tonnes , et le second les marchandises de
plus de deux Tonnes.
Dans les 2 cas, les clés sont celles des marchandises, et les valeurs des listes de marchandises avec leurs propriétés et
leurs destinations.
2. On souhaite soulager le bateau léger car l’autre bateau possède encore de la capacité. Le bateau léger possède tous
les types de marchandises, et le bateau lours seulement quelques unes. Il a été décidé de transférer des marchandises
communes (pour des raisons administratives, il est plus facile de modifier les quantités de marchandises que d’en
rajouter de nouvelles dans un bateau).
Ecrire un programme qui va prendre les 2 dictionnaires précédents et qui va donc créer un 3ème dictionnaire contenant
seulement les clés communes aux deux (ainsi que la fusion de leurs valeurs).
Vérifier que les 2 bateaux ne possèdent plus de types de marchandises en commun, et que le bateau lourd a été rempli
"""

def batal(cargo): 
    light_ship={}
    heavy_ship={}
    for type in cargo:
        for tuple in cargo[type]:
            poid=tuple[1]*tuple[2]
            print(poid)
            if poid <2000 : 
                if type not in light_ship:
                    light_ship[type]=[]
                light_ship[type].append(tuple)
            else :
                if type not in heavy_ship:
                    heavy_ship[type]=[]
                heavy_ship[type].append(tuple)
    ("leger \n")
    print_dict(light_ship)
    print("lourd\n")
    print_dict(heavy_ship)
    print("cargo\n")
    print_dict(cargo)
                


batal(cargo)
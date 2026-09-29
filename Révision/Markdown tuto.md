Pour créer un fichier Markdown, il suffit de créer un nouveau fichier dans Visual Studio Code et de le nommer avec l'extension `.md` (par exemple `revisions_systeme.md`).

Voici la syntaxe pour structurer tes fiches de révision et intégrer tes scripts avec la bonne coloration syntaxique.

**1. Le code en ligne (dans une phrase)**
Pour mettre en évidence une commande courte ou un nom de variable au milieu d'un paragraphe, entoure le texte avec un seul *backtick* (l'accent grave `). *Exemple :* Pour lister les fichiers cachés sous Unix, utilise la commande`ls -la`.

**2. Les blocs de code (Boîtes de code complètes)**
Pour créer une boîte contenant plusieurs lignes de code, tu dois l'ouvrir avec trois *backticks* (```) suivis immédiatement du nom du langage (pour activer les bonnes couleurs), et la fermer avec trois *backticks* seuls sur une nouvelle ligne.

Voici les balises exactes pour les matières de ton cursus :

**Pour Unix / Commandes Linux**


```bash
cd /home/dossier
mkdir nouveau_projet
ls -la
```



**Pour Python**


```python
def calculer_moyenne(notes):
    return sum(notes) / len(notes)
```



**Pour le langage C**


```c
#include <stdio.h>

int main() {
    printf("Hello World\n");
    return 0;
}
```


**Pour l'Algorithmique (ADO / Pseudo-code)**
Le pseudo-code n'étant pas un langage de programmation standardisé, il n'a pas de balise officielle. Tu peux utiliser la balise `text` (pour du texte brut sans fausse coloration) ou `pascal` (qui offre des couleurs assez adaptées à la structure du pseudo-code algorithmique français).


```text
Variables:
    n, i : Entier
Début
    Pour i allant de 1 à n Faire
        Afficher(i)
    FinPour
Fin
```



**3. Raccourcis et bonnes pratiques dans VS Code**

* **Auto-fermeture :** Sous VS Code, lorsque tu tapes tes trois premiers backticks et que tu appuies sur Entrée, l'éditeur crée automatiquement la balise de fermeture en dessous. Ton curseur se place au milieu, prêt à taper.
* **Vérification visuelle :** Pense à utiliser ton raccourci `Ctrl` + `K` puis `V` : tes blocs de code apparaîtront sous forme de boîtes grisées, avec les mots-clés (comme `def`, `int`, ou `return`) colorés exactement comme dans ton éditeur classique.
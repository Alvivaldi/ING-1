# TD 01 : Commandes UNIX

Semestre 1 - ING1 GI

---

## Exercice 1 : Naviguer dans le système

**1. Aller dans le répertoire `bin` du système et afficher son contenu**

```bash
cd /bin
ls -l
```

*Explication :* `cd` permet de changer de répertoire (Change Directory). L'option `-l` de `ls` affiche le contenu sous forme de liste détaillée.

### 2. Revenir dans le dossier utilisateur (4 manières)

```bash
cd          # Méthode 1 : cd sans argument ramène toujours au dossier personnel
cd ~        # Méthode 2 : Le tilde ~ est le raccourci Unix pour le répertoire de l'utilisateur
cd $HOME    # Méthode 3 : Utilise la variable d'environnement système
cd -        # Méthode 4 : Ramène au répertoire précédent dans l'historique
```

---

## Exercice 2 : Création de fichier

**1. Que fait la commande `vi TP1` ?**

Elle ouvre l'éditeur de texte en ligne de commande `vi` (ou crée le fichier s'il n'existe pas) pour éditer un fichier nommé `TP1`.

**2. Créer `hello.c` et afficher son type**

```bash
nano hello.c
```

*Dans l'éditeur, écrire le code minimal :*

```c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}
```

*Pour afficher le type de contenu :*

```bash
file hello.c
```

*Résultat attendu :* `C source, ASCII text`

**3. Compiler `hello.c` et afficher le type de l'exécutable**

```bash
gcc hello.c -o hello
file hello
```

*Résultat attendu :* `ELF 64-bit LSB executable...` (Fichier binaire exécutable).

### 4. Créer le fichier "mes Musiques"

```bash
nano "mes Musiques"
```

*Explication :* L'utilisation des guillemets est obligatoire car il y a un espace dans le nom du fichier. Sans cela, Unix croirait qu'on veut créer deux fichiers : "mes" et "Musiques".

### 5 & 6. Afficher le contenu et le type de "mes Musiques"

```bash
cat "mes Musiques"  # Affiche le texte écrit dedans
file "mes Musiques" # Affichera "ASCII text"
```

---

## Exercice 3 : Copie et déplacement

### 1 & 2. Copier et comparer la taille

```bash
cp "mes Musiques" myMusic
ls -l "mes Musiques" myMusic
```

*Explication :* La taille (affichée en octets dans la 5ème colonne de `ls -l`) sera exactement identique car `cp` fait un clone parfait.

**3. Renommer `myMusic` en `mySongs`**

```bash
mv myMusic mySongs
```

**4. Différence entre `mv` et `cp` ?**

* `cp` (Copy) duplique le fichier. L'original est conservé.
* `mv` (Move) déplace ou renomme le fichier. L'original disparaît.

---

## Exercice 4 : Création de dossiers

**1 & 2. Créer `myFiles`, déplacer et renommer en une commande**

```bash
mkdir myFiles
mv mySongs myFiles/songs2
```

### 3. Créer les sous-dossiers sans se déplacer

```bash
mkdir -p myFiles/Albums/favorites myFiles/Artistes
```

*Explication :* L'argument `-p` (parents) permet de créer toute l'arborescence d'un coup (crée `Albums` et `favorites` à l'intérieur, même si `Albums` n'existait pas encore).

---

## Exercice 5 : Suppression de fichiers/dossiers

**1. Supprimer avec `rm`**

```bash
rm myFiles
```

*Résultat :* Erreur (`rm: cannot remove 'myFiles': Is a directory`). `rm` classique ne supprime que des fichiers.

**2. Supprimer avec `rmdir`**

```bash
rmdir myFiles
```

*Résultat :* Erreur (`rmdir: failed to remove 'myFiles': Directory not empty`). `rmdir` ne fonctionne que sur des dossiers totalement vides.

### 3. Supprimer de force (récursif)

```bash
rm -r myFiles
```

*Explication :* Le `-r` (recursive) rentre dans le dossier et supprime tout le contenu avant de supprimer le dossier lui-même.

### 4 & 5. Comportement si le fichier n'existe pas

```bash
rm -r myFiles   # Résultat : Erreur (No such file or directory)
rm -rf myFiles  # Résultat : Aucune erreur, la commande est silencieuse
```

*Explication :* Le `-f` (force) ignore les fichiers inexistants et ne renvoie pas d'erreur.

---

## Exercice 6 : Droits d'accès

### 1. Afficher les droits d'un répertoire

```bash
ls -ld nom_du_repertoire
```

**2. Analyse des droits `drwx--x--x`**

* **Peut-il afficher le contenu ?** Non. Le droit de lecture `r` est absent pour le groupe et les autres.
* **Que peut-il faire ?** Le droit `x` sur un dossier donne le droit de le "traverser". L'utilisateur peut donc faire un `cd` à l'intérieur s'il connaît déjà le nom d'un sous-fichier exact, mais il ne peut pas lister ce qu'il y a dedans avec `ls`.

### 3. Création et droits restrictifs

```bash
mkdir Moi
chmod 753 Moi
```

*Pertinence de `drwxr-x-wx` :* Très mauvais ! Cela signifie que "les autres" (le reste du monde) ont le droit d'écrire (`w`) et d'exécuter (`x`) dans le dossier, mais pas de le lire (`r`).

*Proposition de droits restrictifs standard (Seul le propriétaire a tous les droits, les autres n'ont rien) :*

```bash
chmod 700 Moi
```

---

## Exercice 7 : Alias de commandes

**1 & 2. Qu'est-ce qu'un alias ?**

Un alias est un raccourci personnalisé pour remplacer une commande longue. Si un alias a le même nom qu'une commande existante, c'est l'alias qui prend le dessus et s'exécute à la place de la vraie commande.

### 3 & 4. Créer et supprimer un alias

```bash
alias cd='ls'
cd         # Exécute ls au lieu de changer de dossier
unalias cd # Supprime l'alias
cd         # Refonctionne normalement
```

**5 & 6. Créer `myDirs` et tester la persistance**

```bash
alias myDirs='ls -d ~/*/'
```

*Si on ferme et rouvre le terminal :* L'alias ne marche plus. Les alias créés dans le terminal sont temporaires à la session en cours.

**7, 8 & 9. Rendre l'alias permanent dans `.bashrc`**

```bash
cat ~/.bashrc
```

Ce fichier contient la configuration de session du terminal (variables, couleurs, et alias au démarrage).

*Pour l'ajouter définitivement :*

```bash
nano ~/.bashrc
# Ajouter à la fin du fichier : alias myDirs='ls -d ~/*/'
```

Dans la session actuelle, cela ne marche pas immédiatement car le `.bashrc` n'est lu qu'à l'ouverture. Si on ferme et rouvre le terminal, l'alias `myDirs` fonctionnera de manière permanente.

---

## Exercice 8 : Aller plus loin

### 1. Shell utilisé

```bash
echo $SHELL
```

*(Généralement `/bin/bash` sur Ubuntu).*

### 2. Version du système

```bash
cat /etc/os-release
# ou
uname -a
```

**3. Chemin absolu de `cat`**

```bash
which cat
```

*(Résultat : `/usr/bin/cat` ou `/bin/cat`).*

**4. Rôle du `.bashrc`**

C'est un script caché exécuté automatiquement à chaque fois qu'on ouvre une nouvelle fenêtre de terminal. Il sert à préparer l'environnement de travail de l'utilisateur.

**5. Rôle de la commande `history`**

Elle affiche l'historique complet numéroté de toutes les commandes tapées précédemment dans le terminal.
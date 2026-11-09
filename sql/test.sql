/*
sudo service mysl start
mysql -u root -p
use pokemons;

*/

DROP TABLE IF EXISTS Apparition;
DROP TABLE IF EXISTS Pokemon;
DROP TABLE IF EXISTS Joueur;
DROP TABLE IF EXISTS Emplacement;
DROP TABLE IF EXISTS Equipe;

CREATE TABLE Equipe(
    id INT PRIMARY KEY,
    nom VARCHAR(50),
    couleur VARCHAR(20)
);

CREATE TABLE Emplacement(
    id INT PRIMARY KEY,
    latitude FLOAT,
    longitude FLOAT
);


CREATE TABLE Joueur (
    pseudonyme VARCHAR(50) PRIMARY KEY,
    personnage VARCHAR(50),
    sexe CHAR(1),
    niveau INT,
    idEquipe INT,
    FOREIGN KEY (idEquipe) REFERENCES Equipe(id)
);

CREATE TABLE Pokemon (
    id INT PRIMARY KEY,
    nom VARCHAR(50),
    espece VARCHAR(50),
    pointCombat INT,
    idJoueur VARCHAR(50),
    FOREIGN KEY (idJoueur) REFERENCES Joueur(pseudonyme)
);

CREATE TABLE Apparition (
    idPokemon INT,
    idEmplacement INT,
    horaire DATETIME,
    duree INT,
    -- La clé primaire ici est composée des 3 éléments qui rendent une apparition unique
    PRIMARY KEY (idPokemon, idEmplacement, horaire),
    FOREIGN KEY (idPokemon) REFERENCES Pokemon(id),
    FOREIGN KEY (idEmplacement) REFERENCES Emplacement(id)
);
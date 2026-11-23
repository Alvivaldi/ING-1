-- Exercice 1)

-- 1 Insérer les Pokémons

INSERT INTO Pokemon VALUES (19, 'Rattata', 'Souris', 20, 'Admin');
INSERT INTO Pokemon VALUES (39, 'Rondoudou', 'Bouboule', 4145, 'Moustache');

-- 2 Equipe 3 à prit l'arène 2 le 10 octobre 2016

INSERT INTO Defense VALUES (3, 2, '2016-10-10');

-- 3 Equipe 2 à prit l'arène 3

INSERT INTO Defense (idEquipe, idArene) VALUES (2, 3);

-- 4 Insérer des Joueurs

INSERT INTO Joueur VALUES ('Flavius', 'Ruth', 'M', 20, 2);
INSERT INTO Joueur VALUES ('Asterix', 'Ruth', 'M', 5, 1);

-- 5 Mettre le niveau 15 à toutes les femmes

UPDATE Joueur SET niveau = 15 WHERE sexe = 'F';

-- 6 Enlever les Pokémons avec "fruit"

DELETE FROM Pokemon WHERE espece LIKE '%fruit%';

DELETE FROM Apparition WHERE idPokemon = 103;
DELETE FROM Pokemon WHERE espece LIKE '%fruit%';

-- 7 Enlever les Joueurs avec comme pseudo "Admin"

DELETE FROM Joueur WHERE pseudonyme = 'Admin';
-- marche pas car il a encore des pokémons

DELETE FROM Pokemon WHERE idJoueur = 'Admin';

UPDATE Pokemon SET idJoueur = NULL WHERE idJoueur = 'Admin';

-- puis le supprimer

DELETE FROM Joueur WHERE pseudonyme = 'Admin';

-- Exercice 2)
-- 1. Quel est l'arène dont le nom contient le mot "eisti" ?
-- il faut donner requete 
select * from Arere Where nom like '%eisti%';
select * from Arere Where lower(nom) like '%eisti%';


SELECT * FROM Pokemon WHERE LOWER(nom) LIKE 'p%';
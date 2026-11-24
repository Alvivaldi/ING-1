

--Q3

SELECT pseudonyme
    -> FROM Joueur
    -> WHERE LENGTH(pseudonyme) > ALL (SELECT LENGTH(personnage) FROM Joueur);


--Q4
SELECT dateControle AS date_evenement FROM Defense
UNION
SELECT horaire FROM Apparition;


--q5
SELECT dateControle FROM Defense
INTERSECT
SELECT horaire FROM Apparition;

--q6
SELECT *
FROM Joueur
WHERE (pseudonyme LIKE 'A%' OR pseudonyme LIKE 'S%')
  AND personnage != 'Bob';

--q7

SELECT nom
FROM Pokemon
WHERE idJoueur = 'Admin';0
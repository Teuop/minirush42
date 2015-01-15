# Snake en console

Auteur du mini rush: hhismans

Source: https://github.com/hhismans/rush_snake

Temps imparti: 3h

### Ressources disponibles:
- votre libft;
- la fonction `getarrowkey(void)` (fournie);
- la fonction `system("CLEAR")` (avec `#include <stdlib.h>`);
- les fonctions `sleep()` et `usleep()`.

### Man de la fonction getarrowkey (fournie):

Le prototype de cette fonction est : `int	getarrowkey(void);`

return value:
- 0 si l'utilisateur n'appuie sur rien;
- 1 si l'utilisateur appuie sur Flèche de gauche;
- 2 si l'utilisateur appuie sur Flèche du haut;
- 3 si l'utilisateur appuie sur Flèche du bas;
- 4 si l'utilisateur appuie sur  Flèche de droite.

(à utiliser dans une boucle infinie, voir main d'exemple)

## Consignes:

### Ex00:

Ecrire un programme qui affichera une grille de ce type:

	####################
	#                  #
	#                  #
	#    s             #
	#                  #
	#                  #
	#                  #
	#                  #
	#                  #
	#                  #
	####################

- '#' represente les bords de la map;
- 's' représente votre personnage;
- ' ' (space) représente les endroits où votre personnage peut se déplacer;
- votre personnage doit pouvoir se déplacer dans la map à l'aide des flèches clavier;
- l'exécution du programme s'arrête si le personnage rentre en intersection avec un bord de map;
- vous avez le choix pour la hauteur et la largeur de la map.

### Ex01:
__exercice rétrovalidable__

__Le but de ce mini rush est de recoder le jeu SNAKE.__

Vous devez écrire un programme qui prendra en paramètre:
- (1) la largeur du plateau;
- (2) la hauteur du plateau;
- (3) la vitesse du serpent (en cases par seconde par exemple).

Exemple: ./snake 36 10 3

#### Règles du jeu:
- le terrain est délimité par des #;
- le serpent est représenté par des s;
- la pomme est représentée par un a;
- le serpent grandi de 1 quand il mange une pomme;
- une fois la pomme mangée, la pomme repop aléatoirement sur la map;
(cf: google pour générer de l'aléatoire);
- le serpent meurt quand il rencontre un # (ou quand il fait demi-tour ou se mort la queue).

Exemple:

	####################################
	#                                  #
	#       ssssss                     #
	#            s                     #
	#            s                     #
	#                                  #
	#                     a            #
	#                                  #
	#                                  #
	####################################

### Bonus:
- coder à la norme...;
- système de score;
- utiliser une map depuis un fichier (avec des obstacle au milieu par exemple);
- bonus qui apparaît temporairement (lettre b);
- le serpent peut "traverser" les mur (il se téléporte au mur opposé);
- ajouter des couleurs.

Exemple bonus:

	####################################
	#                                  #
	#       ssssss         ##          #
	#            s         ##          #
	#            s                     #
	#                                  #
	#      b              a    ##      #
	#                          ##      #
	#                                  #
	####################################

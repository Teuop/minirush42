# Structures de données

Temps imparti: 3h

Auteur du mini rush: sbenning

Ressources disponibles:

- votre libft,
- votre imagination,
- votre get_next_line.

### Préambule:

Le C est un langage fortement typé: il garantit que les types de données employés décrivent correctement les données manipulées. De plus c’est un langage bas niveau: il permet de manipuler explicitement des registres, des adresses mémoires, voire des instructions machines.

Dans les exercices suivants, si les protos des fonctions ne sont pas donnés, c'est voulu.

### Ex0: Tableaux de pointeurs, pointeurs de tableaux et adresses.

Ecrire la fonction ft_destroy() qui libère la mémoire des éléments d’un tableau de pointeurs sur int, et qui les met à NULL, puis qui libère la mémoire allouée au tableau et met son pointeur à NULL (sa valeur dans la fonction appelante doit avoir été modifiée).

Ecrire la fonction ft_reverse() qui prend en paramètre 2 pointeurs sur tableau d'int et qui inverse leurs valeurs.

### Ex1: Organisation de la mémoire.

Écrire la fonction `char **sort_file(int fd);` qui retourne un tableau de chaînes de caractères contenant les lignes du fd lu (avec get_next_line), triées par ordre alphabétique.

Bonus 0: A chaque ligne doit être associée la taille et le numéro de la ligne dans le fichier. (Vous pouvez pour cela modifier le type renvoyé par la fonction)

Bonus 1: Pourquoi ne pas renvoyer un arbre? Les arbres sont très pratiques pour trier des données. De plus ils nous permettront facilement d’enregistrer tout un tas d’infos (comme pour toute structure).

### Ex2: charset

La structure du code est tout aussi importante que la structure des données. Le but ici, est de se servir d’un CHARSET d’opérations permettant de moduler votre programme avec beaucoup de facilité.

Fichiers à rendre: do_op.c, do_op.h

Votre fichier do_op.h comportera des prototypes de fonctions, des typedef et uniquement les instructions pré-processeur suivantes:

- `#define CHARSET "+-*/"`

- `#define CHARSET_LEN 4`

Ecrire le programme “do_op” qui affiche sur la sortie standard le résultat de l’opération représentée par "arg_v[2]" sur les opérandes "arg_v[1]" et "arg_v[3]".

Exemple:

	$> ./do_op 2 + 3
	$> 5

Seuls les opérateurs représentés dans le CHARSET sont des paramètres valides.

Votre programme devra être modulable: l’ajout d’un opérateur dans le CHARSET devra entrainer un minimum de modification du code. 

Bonus 0: Ajouter l’opérateur modulo '%' au CHARSET. (Si le code est bien organisé il suffit de rajouter une fonction et 1 ou 2 lignes de code).

Bonus 1: Aucun caractère écrit en dur ('X') ne doit apparaître dans le code.

Bonus 2: Aucune instruction conditionnelle (hormis pour la gestion d’erreur) autres que celles présente dans votre libft.

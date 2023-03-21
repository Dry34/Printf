# My_printf
***
Reproduire intégralement la fonction printf du language c ainsi que tout ses flags. 

## instalation 
***
Ce projet se permet de créer une librairie nommée libmy.a contenant le nécessaire pour le printf.

    $ git clone git@github.com:Dry34/Printf.git

Puis dans le programme ou vous souhaitez l'utiliser :

    $ #include "path/libmy.a"

## Fonctionnement
***
Ce programme fonctionne avec des pointeurs de fonction et des structures.
Chaque fonction est associée à une lettre à l'aide d'une première structure qui contient le pointeur sur fonction
et un caractère. Nous associons le caractère avec la fonction dans un tableau de cette structure présente au début
du fichier/my_printf.c. afin de renvoyer le bon nombre de caractere chaque fonction doit retourner le nombre de caractere
ou un nombre négatif s'il y a une erreur cela sera compté par la suite.

### Modification
***
#### rajouter une fonction:

Si votre nouvelle fonction est dans un des fichier fonction_*nombre*_print.c déjà présent, rajouter votre fonction
dans le header *include/my_struct.h* puis associer la fonction à un caractère dans le tableau présent au début de
my_printf.c.

Si vous avez besoin de crée d'autre fichier pour les fonction penser a les rajouter a la main au Makefile afin qu'il puisse
Compiler correctement 

#### rajouter des test unitaire:

Vous trouverez tous les tests unitaires dans le répertoire tests/vous avez uniquement à en rajouter ou
dans le fichier déjà existant ou dans un autre fichier afin de les faire fonctionner. Les tests unitaires fonctionnent.
avec criterion veiller donc à ne pas laisser de main ou que ce soit. 

### executer les test unitaie
***
si vous souhaiter juste savoir si les test se sont bien passer taper la commande:

    $ make tests_run
    
si en plus de ca vous souhaiter avoir une vision sur votre couverture de ligne et de branche taper la commande:

    $ make test_cover
cela aura pour effet de vous ouvrir une page html avec votre couverture precise.


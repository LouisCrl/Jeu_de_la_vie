Documentation

Description du Jeu de la vie 
Le jeu de la vie est un automate cellulaire décrivant l’évolution d’une population de cellules sur un intervalle déterminé ou indéterminé de générations. Les cellules sont placées sur une grille rectangulaire bi dimensionnelle. Les cellules se trouvant dans la grille peuvent être de plusieurs états distincts : 
-	vivante (symboliser par une cellule verte)
-	morte (symboliser par une cellule noir)
On peut décider d’introduire des cellules obstacles, ces cellules serons morte ou vivante, elles le resteront tout au long du jeu. Pour différencier les cellules obstacles des cellules ‘’traditionnel’’ on leurs attribut une couleur différentes (les cellules mortes seront rouge, les vivantes seront bleu).
A chaque itérations, l’état des cellules est mis à jour en fonction de deux règles :
-	Une cellule morte possédant exactement trois voisines vivantes devient vivante.
-	Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

Documentation Utilisateurs
La procédure pour lancer le jeu de la vie se décompose en plusieurs étapes.
Création du fichier
Il faut tout d’abord avoir un fichier txt contenant des informations comme le nombre de lignes, de colonnes, ou encore l’état des cellules.
La première ligne de notre fichier doit contenir le nombre de ligne puis le nombre de colonnes.
Le fichier doit ensuite contenir une matrice de charactère décrivant l’état initial des cellules, vivante(0), obstacle vivante(I), morte(1), obstacle morte(X)
Une fois créer, le fichier est censé être de la forme :
 


Lancements du programme
Premièrement, le lancement du programme se fait dans le terminal wsl grâce à la commande ‘’make’’.
L’utilisateur doit indiquer le chemin du fichier crée précédemment afin d’en récupérer ses informations.
Le jeu demande ensuite à l’utilisateur de choisir entre l’affichage console(1) et l’affichage graphique(2).
A présent on a deux cas de figures :
Le jeu est en affichage Console 
Il est demandé à l’utilisateur d’entrer le nombre d’itérations qu’on souhaite effectuer dans le jeu. Suite à cela le jeu s’exécutera automatiquement, nous renvoyant l’état de la grille sur la console. De plus, le programme crée un nouveau fichier de la forme ‘’nom du fichier’’ + ‘’_out.txt’’, ce fichier aura stocké les états de la grille durant chaque itération.
Le jeu est en affichage Graphique
Le programme va créer un affichage visuel de la grille, la grille comportera toutes les cellules avec leurs états précédemment définie dans le fichier. L’utilisateur pourra, avec un clic gauche sur une cellule, en changer l’état. Avec le clique droit, l’utilisateur décidera de rendre la cellule obstacle ou non.
Quand la configuration des cellules est terminé, la touche ‘’entrée’’ nous permet de lancer le jeu.
A la droite de l’écran apparaitra une jauge, cette jauge représente la vitesse à laquelle la grille va être mis à jour, la vitesse est modifiable grâce aux flèches verticales, la flèche haute réduit l’intervalle de 20ms.
Avec la touche ‘’espace’’, on peut mettre en pause et enlever la pause dans le jeu.
Pour arrêter le programme il nous suffit de cliquer sur la croix en haut à droite de la grille.










Documentation technique

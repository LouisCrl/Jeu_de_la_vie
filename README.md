Documentation 

 

Description du Jeu de la vie  

Le jeu de la vie est un automate cellulaire décrivant l’évolution d’une population de cellules sur un intervalle déterminé ou indéterminé de générations. Les cellules sont placées sur une grille rectangulaire bidimensionnelle. Les cellules se trouvant dans la grille peuvent être de plusieurs états distincts :  

vivante (symbolisée par une cellule verte) 

morte (symbolisée par une cellule noir) 

On peut décider d’introduire des cellules obstacles, ces cellules seront mortes ou vivantes, elles le resteront tout au long du jeu.  

A chaque itérations, l’état des cellules est mis à jour en fonction de deux règles : 

Une cellule morte possédant exactement trois voisines vivantes devient vivante. 

Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt. 

La grille est une grille thorique, c’est-à-dire qu’une cellule en bordure aura des voisins à l’opposé de son emplacement. Les cellules évoluent donc sans bordure, la grille est théoriquement infinie. 

Documentation Utilisateurs 

La procédure pour lancer le jeu de la vie se décompose en plusieurs étapes. 

Création du fichier 

Il faut tout d’abord avoir un fichier .txt contenant des informations comme le nombre de lignes, de colonnes, ou encore l’état des cellules. 

La première ligne de notre fichier doit contenir le nombre de lignes puis le nombre de colonnes. 

Le fichier doit ensuite contenir une matrice de caractère décrivant l’état initial des cellules, vivante(1), obstacle vivante(3), morte(0), obstacle morte(2). 

Une fois crée, le fichier est censé être de la forme : 


![image](https://github.com/user-attachments/assets/0331d8a3-346b-47ad-b193-1c5e341fc8d8)



 

 

Lancements du programme 

Premièrement, le lancement du programme se fait dans le terminal wsl grâce à la commande ‘’make’’. 

L’utilisateur doit indiquer le chemin du fichier créé précédemment afin d’en récupérer ses informations. 

Le jeu demande ensuite à l’utilisateur de choisir entre l’affichage console(1) et l’affichage graphique(2). 

A présent, on a deux cas de figure : 

Le jeu est en affichage Console  

Il est demandé à l’utilisateur d’entrer le nombre d’itérations qu’on souhaite effectuer dans le jeu. Suite à cela, le jeu s’exécutera automatiquement, nous renvoyant l’état de la grille sur la console. De plus, le programme crée un nouveau fichier de la forme ‘’nom du fichier’’ + ‘’_out.txt’’, ce fichier aura stocké les états de la grille durant chaque itération. 

Le jeu est en affichage Graphique 

Le programme va créer un affichage visuel de la grille, la grille comportera toutes les cellules avec leurs états précédemment définis dans le fichier. L’utilisateur pourra, avec un clic gauche sur une cellule, en changer l’état. Avec le clic droit, l’utilisateur décidera de rendre la cellule obstacle ou non. 

Quand la configuration des cellules est terminée, la touche ‘’entrée’’ nous permet de lancer le jeu. 

A la droite de l’écran apparaîtra une jauge, cette jauge représente la vitesse à laquelle la grille va être mise à jour, la vitesse est modifiable grâce aux flèches verticales, la flèche haute réduit l’intervalle de 20ms. 

Avec la touche ‘’espace’’, on peut mettre en pause et enlever la pause dans le jeu. 

Pour arrêter le programme, il nous suffit de cliquer sur la croix en haut à droite de la grille. 



Documentation technique 

 

Méthode utilisée pour coder le jeu 

Le jeu de la vie a été codé en C++, pour rendre le code plus lisible et plus modulable, la Programmation Orientée Objet a été utilisée pour aboutir à ce projet. 

Les différentes Classes ont été organisées en suivant le modèle MVC (Modèle View Controller) qui permet une répartition des tâches optimales ainsi qu’une modularité plus importante. 

Chaque classe est créée grâce à deux fichiers distincts : 

Un fichier d’en-tête (.h) qui sert à déclarer la classe ainsi que ses variables et ses méthodes 

Un fichier source (.cpp) qui contient les définitions des méthodes 

 

Organisation et liaisons des classes 

Il y a un total de 10 Classes : 

- View 

Fait le lien ‘’visuel’’ entre l’utilisateur et le contrôleur. 

- Controller  

Nous permet de lancer la création de la partie, de la lancer ou de l’arrêter. Ces actions sont initiées par la Classe View. 

- Game (virtual) 

C’est une classe virtuelle qui va nous permettre de créer le jeu, et de lancer les n itérations du jeu. 

- Graphic et Console 

Ces deux classes héritées de la Classes Game nous permettent de lancer la Parti dans le mode d’affichage souhaité. Le mode Graphic nous permettra d’interagir avec la grille et d’avoir un aspect plus visuel de cette dernière. Au contraire, le mode Console renverra l’état de la grille directement dans la console. 

- File 

Cette classe va nous permettre de gérer toutes les interactions en lien avec les fichiers .txt, allant de la lecture du fichier jusqu’à l’écriture de l’état de la grille à chaque itération. 

- Grid  

La classe Grid est une agrégation de la Classe Game, elle nous permet d’avoir un accès à la grille à chaque itération. De plus, cette classe permettra de mettre à jour l’état des cellules à chaque itération. 

- Cell (virtual) 

Cette classe permet à la classe Grid d’avoir accès aux états des différentes cellules à chaque itération. A chaque itération, l’état de chaque cellule est mis à jour grâce aux méthodes vie() et meurt() de cette classe. 

- Obs_Cell et N_Cell 

Ces deux Classes sont hérité de la Classe Cell vue précédemment. Elles permettent de rendre les cellules Obstacles (Obs_Cell) ou Normal (N_Cell) lors de leurs créations. Dans la Classe Obs_Cell, les méthodes vie() et meurt() ne changent donc pas l’état des cellules. 

 

Ci-dessous, un diagramme de classe donnant une représentation plus imagée de l’organisation des classes dans le programme : 

 

 
![Class diagram](https://github.com/user-attachments/assets/340dbf0a-1d39-43f9-8e50-685e43170d46)

 

 

Un dossier Github a été créé pour répertorier tous les diagrammes et les codes : 

Lien Github 
https://github.com/LouisCrl/Jeu_de_la_vie

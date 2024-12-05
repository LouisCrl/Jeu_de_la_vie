#include <iostream>
#include <fstream>
#include <vector>           //on importe les différentes bibliothèques utilisé dans la classe
#include <string>
#include "Fichier.h"
#include "Cell.h"           //la classe Cell nous servira à creer notre vector de vector de Cellules

//_______________________________________________________________________________________________________________________________________________________________________

Fichier::Fichier(std::string chemin){       //constructeur

    this -> pass = chemin;                  //pass est le chemin du fichier txt
    this -> ligne = 5;                      //nombre de ligne
    this -> colonne = 10;                   //nombre de colonne
    get_grille_data();                      //cette fonction va nous servir à ouvrir le fichier pour initialiser
                                            // ligne, colonne et donne

}

//_______________________________________________________________________________________________________________________________________________________________________

void Fichier::get_grille_data(){

    std::ifstream my_file(this -> pass);    //ifstream nous sert à ouvrir le fichier
    std::string ligne, colonne;             //ces string vont nous permettre de récuperer le nombres de lignes et de colonnes
    char data;                              //on va s'en servir pour récupérer l'état des cellules


    if(my_file.is_open()){                  //on vérifie que le fichier s'est bien ouvert

        my_file >> ligne >> colonne;        //la première chaine de charactère sere stocké dans ligne, la deuxième dans colonne
        this -> ligne = std::stoi(ligne);           //stoi nous permet de transformer un char en int
        this -> colonne = std::stoi(colonne);                               


        for (int i=0; i<this -> ligne; i++){                    //on parcour toutes les lignes 

            std::vector<Cell*> ligne_i;                         //à chaque lignes on crée un vector de Cellules

            for (int j=0; j<this -> colonne; j++){              //on parcours tout les éléments de la ligne grâce au nombre de colonnes

                my_file >> data;                                //chaque charactère est lu un par un dans la variable data
                ligne_i.push_back(new Cell(stob(data)));        //on ajoute une cellule dans le vector ligne_i en fonction de data
                                                                //stob est une fonction créer en dessous qui nous permet de transformer un char en un bool
            }

            this -> donne.push_back(ligne_i);                   //on rajoute le vector dans notre vector de vector
        }

    }
}

//_______________________________________________________________________________________________________________________________________________________________________

void Fichier::lire_fichier(){

    std::cout << this -> ligne << " " << this -> colonne << std::endl ; //on affiche le nombre de llignes et de colonnes

    for(int i=0; i<this -> ligne; i++){                                 //on parcours donne ligne par ligne

        for(int j=0; j<this -> colonne; j++){                           //on parcours chaque éléments grâce au nmobre de colonnes
            std::cout << this -> donne[i][j]->estVivant();              //on affiche 1 ou 0 grâce à la fonction estVivant() de la classe Cell
        }

        std::cout << std::endl;                                         //on saute une ligne pour plus de clarté
    }
}

//_______________________________________________________________________________________________________________________________________________________________________

bool Fichier::stob(char str){           //convertion d'un char à un bool

    if (str == '0'){                    //si le char = 0 alors
        return 0;                       //on renvoit 0 (équivaut à false)
    }
    
    return 1;                           //sinon on renvoit 1 (équivaut à true)
}

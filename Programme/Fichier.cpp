#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Fichier.h"


Fichier::Fichier(std::string chemin){

    this -> pass = chemin;
    this -> ligne = 5;
    this -> colonne = 10;
    get_grille_data();

}

void Fichier::get_grille_data(){

    std::ifstream my_file(this -> pass);
    std::string ligne, colonne;
    char data;
    std::vector<std::vector<char>> grille;

    if(my_file.is_open()){

        my_file >> ligne >> colonne;
        this -> ligne = std::stoi(ligne);     
        this -> colonne = std::stoi(colonne);                               
        grille = std::vector<std::vector<char>>(this -> ligne);

        for (int i=0; i<this -> ligne; i++){

            std::vector<bool> ligne_i;

            for (int j=0; j<this -> colonne; j++){

                my_file >> data;
                ligne_i.push_back(stob(data));
                
            }

            this -> donne.push_back(ligne_i);
        }

    }
}




void Fichier::lire_fichier(){

    std::cout << this -> ligne << " " << this -> colonne << std::endl ;

    for(int i=0; i<this -> ligne; i++){

        for(int j=0; j<this -> colonne; j++){
            std::cout << this -> donne[i][j];
        }

        std::cout << std::endl;
    }
}







bool Fichier::stob(char str){

    if (str == '0'){
        return 0;
    }
    
    return 1;
}

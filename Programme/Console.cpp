#include "Console.h"
#include "File.h"
#include <iostream>

//_______________________________________________________________________________________________________________________________________________________________________
//Constructeurs

Console::Console(){
    this->nb_iteration = 5;
    this->file = new File();
    this->grid = new Grid();
}

Console::Console(string pass_file, int nb_iteration){
    this->nb_iteration = nb_iteration;
    this->file = new File(pass_file);
    this->grid = new Grid(file->get_ligne(), file->get_colonne(), file->get_fichier());
}

//_______________________________________________________________________________________________________________________________________________________________________
//Affiche la grille

void Console::print(int i){
    this -> file -> ecrire(i);
    for (int i=0; i<this->grid->getLine(); i++){
        for (int j=0; j<this->grid->getColumn(); j++){
            cout << this->grid->getGrid()[i][j]->estVivant();
        }
        cout << endl;
    }
    cout << endl;
}

//_______________________________________________________________________________________________________________________________________________________________________
//Réalise les itérations

void Console::iteration(){
    for (int i=0; i<this->nb_iteration; i++){
        this->grid->update();
        print(i);
    }
}

Console::~Console(){
}

#include "Console.h"
#include "Fichier.h"
#include <iostream>

Console::Console(string file, int nb_iteration){
    this->nb_iteration = nb_iteration;
    createGrid(file);
}

void Console::createGrid(string file){
    Fichier *f = new Fichier(nom_fichier);
    this->grid = new Grid(f->recup_line(), f->recup_column(), f->lireFichier());
}

void Console::print(){
    for (int i=0; i<this->grid->getLine(); i++){
        for (int j=0; j<this->grid->getColumn(); j++){
            cout << this->grid->getGrid()[i][j]->estVivant();
        }
        cout << endl;
    }
    cout << endl;
}

void Console::iteration(){
    for (int i=0; i<this->nb_iteration; i++){
        this->grid->update();
        print();
    }
}

Console::~Console(){
}
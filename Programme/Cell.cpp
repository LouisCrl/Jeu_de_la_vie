#include "Cell.h"

Cell::Cell(){
    this->etat = 0;
}

Cell::Cell(bool etat){
    this->etat = etat;
}

bool Cell::estVivant(){
    return this->etat;
}

void Cell::vie(){
    this->etat = 1;
}

void Cell::meurt(){
    this->etat = 0;
}
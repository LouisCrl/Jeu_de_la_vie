#include "N_Cell.h"
#include <iostream>

using namespace std;

N_Cell::N_Cell(){
    this->etat = 0;
}

N_Cell::N_Cell(bool etat){
    this->etat = etat;
}

bool N_Cell::estVivant(){
    return this->etat;
}

void N_Cell::vie(){
    this->etat = 1;
}

void N_Cell::meurt(){
    this->etat = 0;
}

N_Cell::~N_Cell(){   
}
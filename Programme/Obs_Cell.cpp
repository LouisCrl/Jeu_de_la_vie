#include "Obs_Cell.h"
#include <iostream>

using namespace std;

Obs_Cell::Obs_Cell(){
    this->etat = 0;
}

Obs_Cell::Obs_Cell(bool etat){
    this->etat = etat;
}

bool Obs_Cell::estVivant(){
    return this->etat;
}

void Obs_Cell::vie(){
    return;
}

void Obs_Cell::meurt(){
    return;
}

Obs_Cell::~Obs_Cell(){   
}

#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cell.h"

class File{

private:
    std::string pass;
    std::string new_pass;
    int ligne;
    int colonne;
    std::vector<std::vector<Cell*>> donne;


public:
    File(std::string chemin);
    void lire_fichier();
    bool stob(char);
    void get_grille_data();
    void ecrire(int num);
    int get_ligne();
    int get_colonne();
    std::vector<std::vector<Cell*>> get_fichier();
};


#endif

#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Obs_Cell.h"
#include "N_Cell.h"

using namespace std;

class File{

private:
    string pass;
    string new_pass;
    int ligne;
    int colonne;
    vector<vector<Cell*>> donne;

public:
    File();
    File(string chemin);
    void lire_fichier();
    bool stob(char);
    void get_grille_data();
    void ecrire(int num);
    int get_ligne();
    int get_colonne();
    vector<vector<Cell*>> get_fichier();

};
#endif
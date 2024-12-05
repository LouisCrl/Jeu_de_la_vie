#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cell.h"

class Fichier{

private:
    std::string pass;
    std::string new_pass;
    int ligne;
    int colonne;
    std::vector<std::vector<Cell*>> donne;


public:
    Fichier(std::string chemin);
    void lire_fichier();
    bool stob(char);
    void get_grille_data();
    void ecrire(int num);

};

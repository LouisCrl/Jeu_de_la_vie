#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cell.h"

using namespace std;

class Fichier{
private:
    string pass;
    string new_pass;
    int ligne;
    int colonne;
    vector<vector<Cell*>> donne;


public:
    Fichier(string chemin);
    void lire_fichier();
    bool stob(char);
    void get_grille_data();
    void ecrire(int num);

protected:

};
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cell.h"

<<<<<<< HEAD
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
=======
class Fichier{

private:
    std::string pass;
    std::string new_pass;
    int ligne;
    int colonne;
    std::vector<std::vector<Cell*>> donne;


public:
    Fichier(std::string chemin);
>>>>>>> c46eea76f77206b79534d70827fcd3657e6f5100
    void lire_fichier();
    bool stob(char);
    void get_grille_data();
    void ecrire(int num);

<<<<<<< HEAD
protected:

};
=======
};
>>>>>>> c46eea76f77206b79534d70827fcd3657e6f5100

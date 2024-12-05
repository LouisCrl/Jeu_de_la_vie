#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Fichier{

private:
    std::string pass;
    int ligne;
    int colonne;
    std::vector<std::vector<bool>> donne;


public:
    Fichier(std::string chemin);
    void lire_fichier();
    bool stob(char);
    void get_grille_data();

};
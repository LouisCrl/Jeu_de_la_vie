#include "Game.h"
#include <string>
#include <vector>

using namespace std;

class Console : public Game{
private:
    int nb_iteration;                               //nombre d'itération

public:
    Console();                                      //Constructeur par défaut
    Console(string pass_file, int nb_iteration);    //Constructeur
    void print(int i);                              //Permet l'affichage des itérations
    void iteration();                               //Réalise les itérations
    ~Console();

protected:

};

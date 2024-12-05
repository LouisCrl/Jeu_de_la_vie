#include "Game.h"
#include <string>
#include <vector>

using namespace std;

class Console : public Game{
private:
    int nb_iteration;

public:
    Console(string file, int nb_iteration);
    void creer_grille(string file);
    void print();
    void iteration();

protected:

};
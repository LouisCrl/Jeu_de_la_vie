#include "N_Cell.h"
#include "Obs_Cell.h"
#include <vector>
#include <string>

using namespace std;

class Grid{
private:
    int line;                                                           //Nombre de lignes
    int column;                                                         //Nombre de colonne
    vector<vector<Cell*>> grid;                                         //Stocke la grille
    void initGrid(int line, int column,vector<vector<Cell*>> grid);     //Initialise la grile

public:
    Grid();                                                             //Constructeur par défaut
    Grid(int line, int column, vector<vector<Cell*>> grid);             //Constructeur
    int getLine();                                                      //Permet d'avoir le nombre de ligne
    int getColumn();                                                    //Permet d'avoir le nombre de colonnes
    vector<vector<Cell*>> getGrid();                                    //Permet d'avoir la grille
    void update();                                                      //Met à jour la grille
    ~Grid();

protected:

};

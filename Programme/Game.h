#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game{
private:

public:
    //void creer_grille();
    virtual void print() = 0;
    virtual void iteration() = 0;
    
protected:
    Grid *grid;
    
};
#endif
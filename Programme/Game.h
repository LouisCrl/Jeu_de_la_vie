#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <string>

using namespace std;

class Game{
private:

public:
    virtual void createGrid() = 0;
    virtual void print();
    virtual void updateRender();
    virtual void iteration() = 0;
    virtual ~Game();
    
protected:
    Grid *grid;
    File *file;
    
};
#endif
#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <string>

using namespace std;

class Game{
private:

public:
    virtual void createGrid(string file);
    virtual void createGrid();
    virtual void print();
    virtual void updateRender();
    virtual void iteration() = 0;
    virtual ~Game();
    
protected:
    Grid *grid;
    
};
#endif

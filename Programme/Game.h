#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include <string>

using namespace std;

class Game{
private:

public:
<<<<<<< HEAD
    virtual void createGrid() = 0;
=======
    virtual void createGrid(string file);
    virtual void createGrid();
>>>>>>> 3f3e9a80f3be3a3e6932c2f93495d26f5b97b306
    virtual void print();
    virtual void updateRender();
    virtual void iteration() = 0;
    virtual ~Game();
    
protected:
    Grid *grid;
<<<<<<< HEAD
    File *file;
    
};
#endif
=======
    
};
#endif
>>>>>>> 3f3e9a80f3be3a3e6932c2f93495d26f5b97b306

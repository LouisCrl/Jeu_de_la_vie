#include "Cell.h"
#include <vector>
#include <string>

using namespace std;

class Grid{
private:
    int line;
    int column;
    vector<vector<Cell*>> grid;
    void initGrid(int line, int column,vector<vector<Cell*>> grid);

public:
    Grid();
    Grid(int line, int column, vector<vector<Cell*>> grid);
    Grid(const Grid& other);
    int getLine();
    int getColumn();
    vector<vector<Cell*>> getGrid();
    int verif(int l, int c, Grid* temp);
    void update();
    ~Grid();

protected:

<<<<<<< HEAD
};
=======
};
>>>>>>> 3f3e9a80f3be3a3e6932c2f93495d26f5b97b306

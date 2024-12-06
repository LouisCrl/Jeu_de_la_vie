#include "Cell.h"
#include <vector>
#include <string>

using namespace std;

class Grid{
private:
    int line;
    int column;
    
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
    vector<vector<Cell*>> grid;

protected:


};

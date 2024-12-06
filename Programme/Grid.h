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
    void update();
    ~Grid();

protected:

};

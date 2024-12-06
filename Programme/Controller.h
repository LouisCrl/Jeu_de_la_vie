//#include "Console.h"
#include "Graphic.h"
#include <string>

using namespace std;

class Controller{
private:
    Game* game;

public:
    void createGameConsole(string file);
    void createGameGraphic(int cellSize, int l, int c);
    void play();
    void deleteGame();

protected:

};
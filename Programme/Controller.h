#include "Console.h"
#include "Graphic.h"
#include <string>

using namespace std;

class Controller{
private:
    Game* game;

public:
    void createGameConsole(string file, int nb_iteration);
    void createGameGraphic(string file, int cellSize);
    void play();
    void deleteGame();

protected:

};
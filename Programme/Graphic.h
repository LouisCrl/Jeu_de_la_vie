#include "Game.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Graphic : public Game{
private:
    long delay = 100;
    int cellSize;
    sf::RenderWindow window;
    bool running = true;

public:
    Graphic();
    Graphic(string pass_file, int cellSize);
    void createGrid();
    void updateRender(int l, int c);
    void iteration();
    ~Graphic();

protected:

};

#include "Game.h"
#include <SFML/Graphics.hpp>

class Graphic : public Game{
private:
    long delay = 150;
    int cellSize;
    sf::RenderWindow window;
    bool running = true;

public:
    Graphic();
    Graphic(int cellSize, int l, int c);
    void createGrid();
    void updateRender();
    void iteration();
    ~Graphic();

protected:

};

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

<<<<<<< HEAD
};
=======
};
>>>>>>> 3f3e9a80f3be3a3e6932c2f93495d26f5b97b306

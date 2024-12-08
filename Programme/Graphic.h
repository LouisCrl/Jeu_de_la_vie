#include "Game.h"
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Graphic : public Game{
private:
    long delay = 100;                           //délai entre 2 itérations de base à 100 milliseconds
    int cellSize;                               //taille des cellules
    sf::RenderWindow window;                    //fenêtre affichée
    bool running = true;                        //booléen pour savoir si le programme tourne

public:
    Graphic();                                  //Constructeur par défaut
    Graphic(string pass_file, int cellSize);    //Constructeur
    void createGrid();                          //Création de la grille graphique
    void updateRender(int l, int c);            //Actualisation de la grille graphique
    void iteration();                           //Boucle des itérations
    ~Graphic();

protected:

};

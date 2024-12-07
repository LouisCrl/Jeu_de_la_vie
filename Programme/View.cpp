#include "View.h"

View::View(int choice, string pass_file){
    this -> choice = choice;
    this -> pass_file = pass_file;

}
void View::lancer_view(){
    if(thischoice == 1){
        Controleur *c = new Controleur();
        int nb_iteration;
        std::cout << "Entrez le nombre d'itération " <<  std::endl;
        std::cin << nb_iteration;

        c -> createGameConsole(this -> pass_file, nb_iteration);
        c -> play();
        c -> deleteGame();
    }
    else(){
        Controleur *c = new Controleur();

        int cell_size;
        std::cout << "Entrez la taille des cellules " <<  std::endl;
        std::cin << cell_size;
        c -> createGameGraphic(this -> pass_file, cell_size);
        c -> play();
        c -> deleteGame();
    }
}
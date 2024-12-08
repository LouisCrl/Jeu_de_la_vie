#include "View.h"

View::View(int choice, string pass_file){
    this -> choice = choice;
    this -> pass_file = pass_file;
}
void View::lancer_view(){
    Controller *c = new Controller();
    if(this->choice == 1){
        int nb_iteration;
        std::cout << "Entrez le nombre d'itération " <<  std::endl;
        std::cin >> nb_iteration;

        c -> createGameConsole(this -> pass_file, nb_iteration);
    }
    else{
        int cell_size;
        std::cout << "Entrez la taille des cellules " <<  std::endl;
        std::cin >> cell_size;
        c -> createGameGraphic(this -> pass_file, cell_size);
    }
    c -> play();
    c -> deleteGame();
}

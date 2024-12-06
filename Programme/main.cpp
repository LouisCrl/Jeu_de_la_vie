#include "Console.h"
#include "Graphic.h"
#include <string>
#include <iostream>

int main(){

    std::string pass_file;
    std::cout << "entrez le chemin du fichier contenant les données : " <<  std::endl;
    std::cin >> pass_file;

    std::cout << "  __________  " <<  std::endl;
    std::cout << "  __________  " <<  std::endl;

    int choice;
    std::cout << "Choix de l'affichage : " <<  std::endl;
    std::cout << "1 = Affichage Console" <<  std::endl;
    std::cout << "2 = Affichage Graphique" <<  std::endl;
    std::cin >> choice;

    if(choice == 1){

        int iteration;
        std::cout << "Entrez le nombre d'itération " <<  std::endl;
        std::cin >> iteration;
        Game *c = new Console(pass_file, iteration);
        c->iteration();
        delete c;
        return 0;
    }
    Game *c = new Graphic(pass_file, 8);
    c->iteration();
    delete c;
    return 0;

}

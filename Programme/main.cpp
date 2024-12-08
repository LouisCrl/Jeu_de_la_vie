#include "View.h"
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

    View v(choice, pass_file);

    v.lancer_view();
    
    return 0;
}

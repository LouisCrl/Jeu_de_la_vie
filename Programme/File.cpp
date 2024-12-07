#include "File.h"

//_______________________________________________________________________________________________________________________________________________________________________

File::File(){       //constructeur

    this -> pass = "base.txt";                  //pass est le chemin du fichier txt
    this -> new_pass = "base.txt";
    get_grille_data();                      //cette fonction va nous servir à ouvrir le fichier pour initialiser
                                            // ligne, colonne et donne

}

File::File(std::string chemin){       //constructeur

    this -> pass = chemin;                  //pass est le chemin du fichier txt
    this -> new_pass = chemin;
    get_grille_data();                      //cette fonction va nous servir à ouvrir le fichier pour initialiser
                                            // ligne, colonne et donne

}

//_______________________________________________________________________________________________________________________________________________________________________

void File::get_grille_data(){

    std::ifstream my_file(this -> pass);    //ifstream nous sert à ouvrir le fichier
    std::string ligne, colonne;             //ces string vont nous permettre de récuperer le nombres de lignes et de colonnes
    char data;                              //on va s'en servir pour récupérer l'état des cellules

    size_t txt_erase = this -> new_pass.find_last_of('.');
    this -> new_pass.erase(txt_erase);
    this -> new_pass += "_out.txt";


    std::ofstream my_save_file(new_pass);   //pour remettre le txt à zéro
    my_save_file.close();

    //std::cout << new_pass << std::endl;



    if(my_file.is_open()){                  //on vérifie que le fichier s'est bien ouvert

        my_file >> ligne >> colonne;        //la première chaine de charactère sere stocké dans ligne, la deuxième dans colonne
        this -> ligne = std::stoi(ligne);           //stoi nous permet de transformer un char en int
        this -> colonne = std::stoi(colonne);                               


        for (int i=0; i<this -> ligne; i++){                    //on parcour toutes les lignes 

            std::vector<Cell*> ligne_i;                         //à chaque lignes on crée un vector de Cellules

            for (int j=0; j<this -> colonne; j++){              //on parcours tout les éléments de la ligne grâce au nombre de colonnes
                my_file >> data;                                //chaque charactère est lu un par un dans la variable data
                if (data == '2'){
                    ligne_i.push_back(new Obs_Cell(stob('0')));
                }else if (data == '3'){
                    ligne_i.push_back(new Obs_Cell(stob('1')));
                }else{
                    ligne_i.push_back(new N_Cell(stob(data)));
                }        //on ajoute une cellule dans le vector ligne_i en fonction de data
                                                                //stob est une fonction créer en dessous qui nous permet de transformer un char en un bool
                //cout << ligne_i[j]->estVivant() << endl;
            }
            cout << endl;

            this -> donne.push_back(ligne_i);                   //on rajoute le vector dans notre vector de vector
        }

    }
    my_file.close();
}

//_______________________________________________________________________________________________________________________________________________________________________

void File::lire_fichier(){

    std::cout << this -> ligne << " " << this -> colonne << std::endl ; //on affiche le nombre de llignes et de colonnes

    for(int i=0; i<this -> ligne; i++){                                 //on parcours donne ligne par ligne

        for(int j=0; j<this -> colonne; j++){                           //on parcours chaque éléments grâce au nmobre de colonnes
            std::cout << this -> donne[i][j]->estVivant();              //on affiche 1 ou 0 grâce à la fonction estVivant() de la classe Cell
        }

        std::cout << std::endl;                                         //on saute une ligne pour plus de clarté
    }
}

//_______________________________________________________________________________________________________________________________________________________________________

void File::ecrire(int num){
    std::ofstream my_save_file(new_pass, std::ios::app);                //std::ios::app est un mod d'ouverture qui ne remet pas le fichier à zéro à l'ouverture
    if (my_save_file.is_open()){
        
        my_save_file << "iteration numéro : " << num << std::endl;
        for(int i=0; i<this -> ligne; i++){   

            for(int j=0; j<this -> colonne; j++){                           
                my_save_file << this -> donne[i][j]->estVivant();              
            }

            my_save_file << std::endl;                                         
        }
        my_save_file << std::endl << std:: endl;

        my_save_file.close();
    }
    //p += "_out.txt";

    //ofstream my_save_file(p);
}

//_______________________________________________________________________________________________________________________________________________________________________

bool File::stob(char str){           //convertion d'un char à un bool

    if (str == '0'){                    //si le char = 0 alors
        return 0;                       //on renvoit 0 (équivaut à false)
    }
    
    return 1;                           //sinon on renvoit 1 (équivaut à true)
}

int File::get_ligne(){
    return this -> ligne;
}
int File::get_colonne(){
    return this -> colonne;
}
std::vector<std::vector<Cell*>> File::get_fichier(){
    return this -> donne;
}

#include "Grid.h"
#include <iostream>

Grid::Grid(){
    vector<vector<Cell*>> grid(5, vector<Cell*>(5, nullptr));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = new N_Cell();

        }
    }
    initGrid(5, 5, grid);
}

Grid::Grid(int line, int column, vector<vector<Cell*>> grid){
    initGrid(line, column, grid);
}

void Grid::initGrid(int line, int column, vector<vector<Cell*>> grid){
    this->line = line;
    this->column = column;
    this->grid = grid;
}

int Grid::getLine(){
    return this->line;
}

int Grid::getColumn(){
    return this->column;
}

vector<vector<Cell*>> Grid::getGrid(){
    return this->grid;
}

void Grid::update(){
    vector<vector<bool>> temp(this->line,vector<bool>(this->column));
    for (int i=0; i<this->line; i++){
        for (int j=0; j<this->column; j++){
            temp[i][j] = this->grid[i][j]->estVivant();
        }
    }
    for (int i=0; i<this->line; i++){
        for (int j=0; j<this->column; j++){
            int count = 0;
            for (int ii=-1; ii<2; ii++){
                for (int ij=-1; ij<2; ij++){
                    if (ii==0 && ij==0) continue;

                    int neighborL = i + ii;
                    int neighborC = j + ij;
                    if (neighborL >= 0 && neighborL < this->line && neighborC >= 0 && neighborC < this->column){ //si tout est normal
                        count += temp[neighborL][neighborC];
                    }
                    
                    else if (neighborL == -1){               //si la voisine se situe au dessus de la matrice
                        if(neighborC >= 0 && neighborC < this->column){           //si l'axe x est correcte
                            count += temp[this -> line -1][neighborC];             //alors on va chercher la cellule en bas qui correspond à la colonne
                        }
                        else if(neighborC == -1){                                  //si la cellule est dans le coin haut gauche
                            count += temp[this -> line -1][this -> column -1];     //on va chercher en bas à droitei
                        }
                        else{                                                      //si la cellule est dans le coin haut droite
                            count += temp[this -> line -1][0];                     //on cherche la cellule en bas à gauche
                        }
                    }
                    
                    else if (neighborL >= 0 && neighborL < this -> line){    //si la cellules voisines est correcte sur l'axe y
                        if(neighborC == -1){                                  //si la cellules est trop à gauche
                            count += temp[neighborL][this -> column -1];      //on va la cherché à droite
                        }
                        else{           //c'est bon
                            count += temp[neighborL][0];
                        }
                    }
                    else{
                        if(neighborC >= 0 && neighborC < this->column){
                            count += temp[0][neighborC];
                        }
                        else if(neighborC == -1){
                            count += temp[0][this -> column -1];
                        }
                        else{
                            count += temp[0][0];
                        }
                        
                    }

                }
            }
            if (count == 3 && (!temp[i][j])){
                this->grid[i][j]->vie();
            }else if ((count < 2 ||count > 3) && (temp[i][j])){
                this->grid[i][j]->meurt();
            }
        }
    }
}

Grid::~Grid(){
    for (int i=0; i<this->line; i++){
        for (int j=0; j<this->column; j++){
            delete this->grid[i][j];
        }
    }
}

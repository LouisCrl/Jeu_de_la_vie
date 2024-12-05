#include "Grid.h"
#include <iostream>

Grid::Grid(){
    vector<vector<Cell*>> grid(this->line, vector<Cell*>(this->column, new Cell())); 
    initialiserGrille(5, 5, grid);
}

Grid::Grid(int line, int column, vector<vector<Cell*>> grid){
    initialiserGrille(line, column, grid);
}

void Grid::initialiserGrille(int line, int column, vector<vector<Cell*>> grid){
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

int Grid::verif(int l, int c, vector<vector<Cell*>> temp){
    int count = 0;
    for (int i=-1; i<2; i++){
        for (int j=-1; j<2; j++){
            if (i==0 && j==0) continue;

            int neighborL = l + i;
            int neighborC = c + j;
            if (neighborL >= 0 && neighborL < this->line && neighborC >= 0 && neighborC < this->column){
                if (temp[neighborL][neighborC]->estVivant()) count++;
            }
        }
    }
    return count;
}

void Grid::update(){
    vector<vector<Cell*>> temp = this->grid;
    int count;
    for (int i=0; i<this->line; i++){
        for (int j=0; j<this->column; j++){
            count = verif(i, j, temp);
            if (count == 3 && (!temp[i][j]->estVivant())){
                this->grid[i][j]->vie();
            }else if ((count < 2 ||count > 3) && (temp[i][j]->estVivant())){
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
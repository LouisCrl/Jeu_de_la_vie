#include "Grid.h"
#include <iostream>

Grid::Grid(){
    vector<vector<Cell*>> grid(5, vector<Cell*>(5, nullptr));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            grid[i][j] = new Cell();

        }
    }
    initGrid(5, 5, grid);
}

Grid::Grid(int line, int column, vector<vector<Cell*>> grid){
    initGrid(line, column, grid);
}

Grid::Grid(const Grid& other){
    this->line = other.line;
    this->column = other.column;
    this->grid.resize(this->line);
    for (int i = 0; i < this->line; ++i) {
        this->grid[i].resize(this->column);
        for (int j = 0; j < this->column; ++j) {
            if (other.grid[i][j] != nullptr) {
                this->grid[i][j] = new Cell(*other.grid[i][j]);
            } else {
                this->grid[i][j] = nullptr;
            }
        }
    }
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

int Grid::verif(int l, int c, Grid *temp){
    int count = 0;
    for (int i=-1; i<2; i++){
        for (int j=-1; j<2; j++){
            if (i==0 && j==0) continue;

            int neighborL = l + i;
            int neighborC = c + j;
            if (neighborL >= 0 && neighborL < this->line && neighborC >= 0 && neighborC < this->column){
                if (temp->getGrid()[neighborL][neighborC]->estVivant()) count++;
            }
        }
    }
    return count;
}

void Grid::update(){
    Grid temp = *this;
    int count;
    for (int i=0; i<this->line; i++){
        for (int j=0; j<this->column; j++){
            count = verif(i, j, &temp);
            if (count == 3 && (!temp.getGrid()[i][j]->estVivant())){
                this->grid[i][j]->vie();
            }else if ((count < 2 ||count > 3) && (temp.getGrid()[i][j]->estVivant())){
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

#include "Controller.h"

void Controller::createGameConsole(string file){
    //this->game = Console(file);
}

void Controller::createGameGraphic(int cellSize, int l, int c){
    this->game = new Graphic(cellSize, l, c);
}

void Controller::play(){
    this->game->iteration();
}

void Controller::deleteGame(){
    delete this->game;
}
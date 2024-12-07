#include "Controller.h"

void Controller::createGameConsole(string file, int nb_iteration){
    this->game = new Console(file, nb_iteration);
}

void Controller::createGameGraphic(string file, int cellSize){
    this->game = new Graphic(file, cellSize);
}

void Controller::play(){
    this->game->iteration();
}

void Controller::deleteGame(){
    delete this->game;
}
#include "Graphic.h"
#include <iostream>

using namespace std;

Graphic::Graphic(){
    this->delay = 100;
    this->cellSize = 100;
    this->grid = new Grid();
    this->window.create(sf::VideoMode(this->grid->getLine() * this->cellSize, this->grid->getColumn() * this->cellSize), "Game of Life");
    createGrid();
}

Graphic::Graphic(long delay, int cellSize, int l, int c){
    this->delay = delay;
    this->cellSize = cellSize;
    vector<vector<Cell*>> vide(l, vector<Cell*>(c, nullptr));
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            vide[i][j] = new Cell();
        }
    }
    this->grid = new Grid(l, c, vide);
    this->window.create(sf::VideoMode(this->grid->getLine() * this->cellSize, this->grid->getColumn() * this->cellSize), "Game of Life");
    createGrid();
}

void Graphic::createGrid(){
    bool start = false;
    sf::Event event;
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    while (!start){
        while (this->window.pollEvent(event)){    
            if (event.type == sf::Event::Closed){
                this->window.close();
                this->running = false;
                return;
            }
            if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    for (int i=0; i<this->grid->getLine(); i++){
                        for (int j=0; j<this->grid->getColumn(); j++){
                            if (event.mouseButton.x >= i*cellSize && event.mouseButton.x <= (i+1)*cellSize && event.mouseButton.y >= j*cellSize && event.mouseButton.y <= (j+1)*cellSize){
                                cell.setPosition(i*cellSize, j*cellSize);
                                if (this->grid->getGrid()[i][j]->estVivant()){
                                    cell.setFillColor(sf::Color::Black);
                                    this->grid->getGrid()[i][j]->meurt();
                                }else{
                                    cell.setFillColor(sf::Color::White);
                                    this->grid->getGrid()[i][j]->vie();
                                }
                                this->window.draw(cell);
                                this->window.display();
                            }
                        }
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Enter){
                    start = true;
                }
            }
            this->window.display();
        }
    }
}

void Graphic::updateRender(){
    this->window.clear();
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    for (int i=0; i<this->grid->getLine(); i++){
        for (int j=0; j<this->grid->getColumn(); j++){
            if (this->grid->getGrid()[i][j]->estVivant()){
                cell.setPosition(i*cellSize, j*cellSize);
                cell.setFillColor(sf::Color::White);
                this->window.draw(cell);
            }
        }
    }
    this->window.display();
}

void Graphic::iteration(){
    while (this->running && this->window.isOpen()) {
        sf::Event event;
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                this->running = false;
                this->window.close();
                return;
            }
        }

        if (this->running){            
            this->grid->update();

            updateRender();

            sf::sleep(sf::milliseconds(this->delay));
        }
    }
}

Graphic::~Graphic(){
}
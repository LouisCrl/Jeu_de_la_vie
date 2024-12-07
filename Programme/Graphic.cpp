#include "Graphic.h"
#include <iostream>

Graphic::Graphic(){
    this->cellSize = 100;
    this->grid = new Grid();
    this->window.create(sf::VideoMode(this->grid->getColumn() * this->cellSize + 30, this->grid->getLine() * this->cellSize), "Game of Life");
    createGrid();
}

Graphic::Graphic(string pass_file, int cellSize){
    this->cellSize = cellSize;
    this->file = new File(pass_file);
    this->grid = new Grid(file->get_ligne(), file->get_colonne(), file->get_fichier());
    this->window.create(sf::VideoMode(this->grid->getColumn() * this->cellSize + 30, this->grid->getLine() * this->cellSize), "Game of Life");
    createGrid();
}

void Graphic::createGrid(){
    updateRender(this->grid->getLine(), this->grid->getColumn());
    bool start = false;
    sf::Event event;
    sf::RectangleShape cell(sf::Vector2f(cellSize-1.0f, cellSize-1.0f));
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
                            if (event.mouseButton.x >= j*cellSize && event.mouseButton.x <= (j+1)*cellSize && event.mouseButton.y >= i*cellSize && event.mouseButton.y <= (i+1)*cellSize){
                                cell.setPosition(j*cellSize, i*cellSize);
                                if (this->grid->getGrid()[i][j]->estVivant()){
                                    cell.setFillColor(sf::Color::Black);
                                    this->grid->getGrid()[i][j]->meurt();
                                }else{
                                    cell.setFillColor(sf::Color::Green);
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

void Graphic::updateRender(int l, int c){
    vector<vector<Cell*>> g = this->grid->getGrid();
    sf::RectangleShape cell(sf::Vector2f(cellSize-1.0f, cellSize-1.0f));
    for (int i=0; i<l; i++){
        for (int j=0; j<c; j++){
            cell.setPosition(j*cellSize, i*cellSize);
            cell.setFillColor(g[i][j]->estVivant() ? sf::Color::Green : sf::Color::Black);
            this->window.draw(cell);
        }
    }
    this->window.display();
}

void Graphic::iteration(){
    bool pause = false;
    
    sf::RectangleShape gaugeBackground(sf::Vector2f(30, this->grid->getLine() * this->cellSize));
    gaugeBackground.setFillColor(sf::Color::White);
    gaugeBackground.setPosition(this->grid->getColumn() * this->cellSize, 0);

    sf::RectangleShape gaugeProgress(sf::Vector2f(30, 0));
    gaugeProgress.setFillColor(sf::Color::Blue);
    gaugeProgress.setPosition(this->grid->getColumn() * this->cellSize, this->grid->getLine() * this->cellSize);
    
    int l = this->grid->getLine();
    int c = this->grid->getColumn();

    while (this->running && this->window.isOpen()) {
        sf::Event event;
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                this->running = false;
                this->window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    pause = !pause;
                }
                if (event.key.code == sf::Keyboard::Down){
                    if (this->delay < 500){
                        this->delay += 20.0f;
                    }
                }
                if (event.key.code == sf::Keyboard::Up){
                    if (this->delay > 20){
                        this->delay -= 20.0f;
                    }
                }
            }
        }
        float gauge = ((520-this->delay) / 500.0f) * (this->grid->getLine() * this->cellSize);
        gaugeProgress.setSize(sf::Vector2f(30, -gauge));
        
        this->window.draw(gaugeBackground);
        this->window.draw(gaugeProgress);
        this->window.display();
        
        if (this->running && (!pause)){   
            this->grid->update();

            updateRender(l, c);

            sf::sleep(sf::milliseconds(this->delay));
        }
    }
}

Graphic::~Graphic(){
}

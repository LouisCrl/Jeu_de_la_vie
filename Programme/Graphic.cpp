#include "Graphic.h"
#include "File.h"

using namespace std;

Graphic::Graphic(){
    this->cellSize = 100;
    this->grid = new Grid();
    this->window.create(sf::VideoMode(this->grid->getLine() * this->cellSize + 30, this->grid->getColumn() * this->cellSize), "Game of Life");
    createGrid();
}

Graphic::Graphic(string pass_file, int cellSize){
    this->cellSize = cellSize;
    this->file = file;
    this->grid = new Grid(this->file.get_ligne(), this->file.get_column(), get_fichier());
    this->window.create(sf::VideoMode(this->grid->getLine() * this->cellSize + 30, this->grid->getColumn() * this->cellSize), "Game of Life");
    createGrid();
}

void Graphic::createGrid(string file){
    bool start = false;
    sf::Event event;
    sf::RectangleShape cell(sf::Vector2f(cellSize-1.0f, cellSize-1.0f));
    
    sf::RectangleShape gaugeBackground(sf::Vector2f(30, this->grid->getColumn() * this->cellSize));
    gaugeBackground.setFillColor(sf::Color::White);
    gaugeBackground.setPosition(this->grid->getLine() * this->cellSize, 0);
    this->window.draw(gaugeBackground);
    
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

void Graphic::updateRender(){
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    for (int i=0; i<this->grid->getLine(); i++){
        for (int j=0; j<this->grid->getColumn(); j++){
            if (this->grid->getGrid()[i][j]->estVivant()){
                cell.setPosition(i*cellSize, j*cellSize);
                cell.setFillColor(sf::Color::Green);
                this->window.draw(cell);
            }else{
                cell.setPosition(i*cellSize, j*cellSize);
                cell.setFillColor(sf::Color::Black);
                this->window.draw(cell);
            }
        }
    }
    this->window.display();
}

void Graphic::iteration(){
    bool pause = false;
    
    sf::RectangleShape gaugeBackground(sf::Vector2f(30, this->grid->getColumn() * this->cellSize));
    gaugeBackground.setFillColor(sf::Color::White);
    gaugeBackground.setPosition(this->grid->getLine() * this->cellSize, 0);

    sf::RectangleShape gaugeProgress(sf::Vector2f(30, 0));
    gaugeProgress.setFillColor(sf::Color::Blue);
    gaugeProgress.setPosition(this->grid->getLine() * this->cellSize, this->grid->getColumn() * this->cellSize);
    
    while (this->running && this->window.isOpen()) {
        sf::Event event;
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                this->running = false;
                this->window.close();
                this->window.close();
                return;
            }

            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    pause = !pause;
                }
                if (event.key.code == sf::Keyboard::Down){
                    if (this->delay < 500){
                        this->delay += 50.0f;
                    }
                }
                if (event.key.code == sf::Keyboard::Up){
                    if (this->delay > 50){
                        this->delay -= 50.0f;
                    }
                }
            }
        }
        float gauge = ((550-this->delay) / 500.0f) * (this->grid->getColumn() * this->cellSize);
        gaugeProgress.setSize(sf::Vector2f(30, -gauge));
        
        this->window.draw(gaugeBackground);
        this->window.draw(gaugeProgress);
        this->window.display();
        
        if (this->running && (!pause)){            
            this->grid->update();

            updateRender();

            sf::sleep(sf::milliseconds(this->delay));
        }
    }
}

Graphic::~Graphic(){
}
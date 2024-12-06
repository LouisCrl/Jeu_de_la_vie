#ifndef CELL_H
#define CELL_H

class Cell{
private:
    bool etat;

public:
    Cell();
    Cell(bool etat);
    bool estVivant();
    void vie();
    void meurt();

protected:

};
#endif
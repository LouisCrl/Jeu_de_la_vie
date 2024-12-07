#ifndef CELL_H
#define CELL_H

class Cell{
private:

public:
    virtual bool estVivant();
    virtual void vie() = 0;
    virtual void meurt() = 0;
    virtual ~Cell();

protected:
    bool etat;
    
};

#endif
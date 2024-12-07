#ifndef OBSCELL_H
#define OBSCELL_H

#include "Cell.h"

class Obs_Cell : public Cell{
private:

public:
    Obs_Cell();
    Obs_Cell(bool etat);
    bool estVivant();
    void vie();
    void meurt();
    ~Obs_Cell();

protected:

};
#endif
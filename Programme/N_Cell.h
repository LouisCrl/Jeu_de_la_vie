#ifndef NCELL_H
#define NCELL_H

#include "Cell.h"

class N_Cell : public Cell{
private:

public:
    N_Cell();
    N_Cell(bool etat);
    bool estVivant();
    void vie();
    void meurt();
    ~N_Cell();

protected:

};
#endif
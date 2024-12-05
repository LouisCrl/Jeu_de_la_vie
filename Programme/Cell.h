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
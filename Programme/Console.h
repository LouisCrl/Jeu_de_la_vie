#include "Game.h"
#include <string>
#include <vector>

using namespace std;

class Console : public Game{
private:
    int nb_iteration;

public:
    Console(string file, int nb_iteration);
    void createGrid(string file);
    void print();
    void iteration();
    ~Console();

protected:

<<<<<<< HEAD
};
=======
};
>>>>>>> 3f3e9a80f3be3a3e6932c2f93495d26f5b97b306

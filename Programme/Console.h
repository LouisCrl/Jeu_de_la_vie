#include "Game.h"
#include <string>
#include <vector>

using namespace std;

class Console : public Game{
private:
    int nb_iteration;

public:
    Console(string pass_file, int nb_iteration);
    void print(int i);
    void iteration();
    ~Console();

protected:

};
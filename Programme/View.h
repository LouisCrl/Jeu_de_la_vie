#include <iostream>
#include "Controller.h"

using namespace std;

class View{

private:
    int choice;
    string pass_file;
    
public:
    View(int choice, string pass_file);
    void lancer_view();
};

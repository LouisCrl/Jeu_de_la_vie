#include <iostream>
#include <stream>
#include "Console.h"
#include "Graphic.h"

using namespace std;

class View{

private:
    int choice;
    string pass_file;
    
public:
    View(int choice, string pass_file);
    void lancer_view();
}
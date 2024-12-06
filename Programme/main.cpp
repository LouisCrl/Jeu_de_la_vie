#include "Console.h"
#include "Graphic.h"

int main(){
    Game *c = new Graphic("test.txt", 8);
    
    c->iteration();
    
    delete c;

    return 0;
}
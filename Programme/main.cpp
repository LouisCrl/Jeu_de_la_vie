#include "Controller.h"

int main(){
    Controller c;
    
    c.createGameGraphic(20, 24, 35);

    c.play();
    
    c.deleteGame();

    return 0;
}
#include "Controller.h"

int main(){
    Controller c;
    
    c.createGameGraphic("test_copy.txt", 40);

    c.play();

    c.deleteGame();

    return 0;
}
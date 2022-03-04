#include "SDL.h"
#include "Game.hpp"
#include <stdio.h>

int main(int argc, char* argv[]) {
    Game game = Game();
    if (game.initializeGame()) game.runGameLoop();
    game.shutDownGame();
    return 0;
}
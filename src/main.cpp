#include "Game.h"

int main(int argc, char** argv) {
    Game const &game = Game::GetInstance();
    game.Run();
    return 0;
}
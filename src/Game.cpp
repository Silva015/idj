#include "Game.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

Game* Game::instance = nullptr;

Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game("Meu Jogo", 1024, 600);
    }
    return *instance;
}

Game::Game(string title, int width, int height) {
    if (instance != nullptr) {
        fprintf(stderr,"Erro: instância de Game já existe %s\n", SDL_GetError());
        exit(1);
    }

    instance = this;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        fprintf(stderr,"Erro: falha ao inicializar SDL %s\n", SDL_GetError());
        exit(1);
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
        fprintf(stderr,"Erro: falha ao inicializar imagem IMG %s\n", SDL_GetError());
        exit(1);
    }

    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) == 0) {
        fprintf(stderr,"Erro: falha ao inicializar biblioteca de sons MIX %s\n", SDL_GetError());
        exit(1);
    }
}
#include "Game.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "State.h"

Game* Game::instance = nullptr;

Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game("ARTHUR SILVA CARNEIRO - 202006321", 1200, 900);
    }

    return *instance;
}

Game::Game(const string &title, int width, int height) {
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

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        fprintf(stderr,"Erro: falha ao inicializar áudio %s\n", SDL_GetError());
        exit(1);
    }

    if (Mix_AllocateChannels(32) != 32) {
        fprintf(stderr,"Erro: falha ao alocar canais de áudio %s\n", SDL_GetError());
        exit(1);
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        fprintf(stderr,"Erro: falha ao criar janela %s\n", SDL_GetError());
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        fprintf(stderr,"Erro: falha ao criar renderizador %s\n", SDL_GetError());
        exit(1);
    }

    state = new State();
}

Game::~Game() {
    delete state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State& Game::GetState() const {
    return *state;
}

SDL_Renderer* Game::GetRenderer() const {
    return renderer;
}

void Game::Run() const {
    while (!state->QuitRequested()) {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}

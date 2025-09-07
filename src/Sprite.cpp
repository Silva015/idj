#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include <string>
#include <SDL2/SDL_image.h>

#include "Game.h"

using namespace std;

Sprite::Sprite() {
    texture = nullptr;
    width = 0;
    height = 0;
    clipRect = {0, 0, 0, 0};
}

Sprite::Sprite(const string& file) {
    texture = nullptr;
    width = 0;
    height = 0;
    clipRect = {0, 0, 0, 0};
    Open(file);
}

Sprite::~Sprite() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(const string& file) {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (texture == nullptr) {
        fprintf(stderr, "Erro: falha ao carregar textura %s\n", SDL_GetError());
        exit(1);
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    clipRect = {0, 0, width, height};
}

void Sprite::SetClip(const int x, const int y, const int w, const int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(const int x, const int y) const {
    SDL_Rect dstrect = {x, y, clipRect.w, clipRect.h};
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth() const {
    return width;
}

int Sprite::GetHeight() const {
    return height;
}

bool Sprite::IsOpen() const {
    return texture != nullptr;
}

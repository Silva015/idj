#define INCLUDE_SDL
#include "SDL_include.h"
#include "Sprite.h"
#include <string>
#include <SDL2/SDL_image.h>

#include "Game.h"

using namespace std;

Sprite::Sprite() : texture(nullptr), width(0), height(0), clipRect{0, 0, 0, 0}, frameCountW(1), frameCountH(1) {
}

Sprite::Sprite(const string &file, const int frameCountW, const int frameCountH)
    : texture(nullptr),
      width(0),
      height(0),
      clipRect{0, 0, 0, 0},
      frameCountW(frameCountW),
      frameCountH(frameCountH) {
    Open(file);
}

Sprite::~Sprite() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(const string &file) {
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

int Sprite::GetWidth() const {
    const int frameW = width / frameCountW;
    return frameW;
}

int Sprite::GetHeight() const {
    const int frameY = height / frameCountH;
    return frameY;
}

void Sprite::SetFrameCount(const int newFrameCountW, const int newFrameCountH) {
    this->frameCountW = newFrameCountW;
    this->frameCountH = newFrameCountH;
}

void Sprite::SetFrame(const int frame) {
    const int frameW = GetWidth();
    const int frameH = GetHeight();
    const int fx = (frame % frameCountW) * frameW;
    const int fy = (frame / frameCountW) * frameH;
    SetClip(fx, fy, frameW, frameH);
}

void Sprite::Render(const int x, const int y, const int w, const int h) const {
    SDL_Rect dstrect = {x, y, w, h};
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

bool Sprite::IsOpen() const {
    return texture != nullptr;
}

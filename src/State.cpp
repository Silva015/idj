#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include "Sprite.h"
#include "Music.h"

void State::LoadAssets() {
    bg.Open("../Recursos/img/Background.png");
    music.Open("../Recursos/audio/BGM.wav");
    music.Play();
}

State::State() {
    LoadAssets();
    quitRequested = false;
}

void State::Update(float dt) {
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}
void State::Render() {
    bg.Render(0, 0);
}

bool State::QuitRequested() const {
    return quitRequested;
}
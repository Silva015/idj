#define INCLUDE_SDL
#include "SDL_include.h"
#include "State.h"
#include "Sprite.h"
#include "Music.h"
#include <algorithm>


void State::LoadAssets() {
    bg.Open("../Recursos/img/Background.png");
    music.Open("../Recursos/audio/BGM.wav");
    music.Play();
}

State::State() {
    LoadAssets();
    quitRequested = false;
}

State::~State() {
    objectArray.clear();
}

void State::Update(float dt) {
    for (auto &go : objectArray) {
        go->Update(dt);
    }

    objectArray.erase(
        std::remove_if(objectArray.begin(), objectArray.end(), [](const std::unique_ptr<GameObject>& go) {
            return go->IsDead();
        }),
        objectArray.end()
    );

    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::Render() const {
    for (auto& go : objectArray) {
        go->Render();
    }

    bg.Render(0, 0);
}

void State::AddObject(GameObject* go) {
    objectArray.emplace_back(go);
}

bool State::QuitRequested() const {
    return quitRequested;
}
#define INCLUDE_SDL
#include "SDL_include.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Zombie.h"
#include "State.h"
#include "Music.h"
#include <algorithm>


void State::LoadAssets() {
    auto *go = new GameObject();
    auto *sr = new SpriteRenderer(*go, "../Recursos/img/Background.png", 1, 1);
    go->AddComponent(sr);
    AddObject(go);

    go = new GameObject();
    go->box.x = 600;
    go->box.y = 450;
    auto *z = new Zombie(*go);
    go->AddComponent(z);
    AddObject(go);

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
    for (auto &go: objectArray) {
        go->Update(dt);
    }

    objectArray.erase(
        std::remove_if(objectArray.begin(), objectArray.end(), [](const std::unique_ptr<GameObject> &go) {
            return go->IsDead();
        }),
        objectArray.end()
    );

    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::Render() const {
    for (auto &go: objectArray) {
        go->Render();
    }
}

void State::AddObject(GameObject *go) {
    objectArray.emplace_back(go);
}

bool State::QuitRequested() const {
    return quitRequested;
}

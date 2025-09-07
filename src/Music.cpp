#define INCLUDE_SDL
#include "SDL_include.h"
#include "Music.h"

Music::Music() {
    music = nullptr;
}

Music::Music(const string& file) {
    music = nullptr;
    Open(file);
}

void Music::Play(const int times) const {
    if (music != nullptr) {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(const int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(const string& file) {
    music = Mix_LoadMUS(file.c_str());
    if (music == nullptr) {
        SDL_Log("Failed to load music: %s", Mix_GetError());
    }
}

bool Music::IsOpen() const {
    return music != nullptr;
}

Music::~Music() {
    if (music != nullptr) {
        Mix_FreeMusic(music);
    }
}



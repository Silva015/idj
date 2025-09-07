#ifndef MUSIC_H
#define MUSIC_H
#include <SDL2/SDL_mixer.h>
#include <string>

using namespace std;

class Music {
public:
    Music();
    explicit Music(const string& file);
    ~Music();
    void Play(int times = -1) const;

    static void Stop(int msToStop = 1500);
    void Open(const string& file);
    bool IsOpen() const;
private:
    Mix_Music *music;
};

#endif
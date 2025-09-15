#ifndef SPRITE_H
#define SPRITE_H
#include <string>
#include <SDL2/SDL_render.h>

using namespace std;

class Sprite {
public:
    Sprite();
    explicit Sprite(const string& file, int frameCountW = 1, int frameCountH = 1);
    ~Sprite();
    void Open(const string& file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y, int w, int h) const;
    int GetWidth() const;
    int GetHeight() const;
    bool IsOpen() const;
    void SetFrame(int frame);
    void SetFrameCount(int frameCountW, int frameCountH);
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect{};
    int frameCountW;
    int frameCountH;
};

#endif
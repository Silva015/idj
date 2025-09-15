#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H
#include <string>

# include "Component.h"
#include "Sprite.h"

using namespace std;

class SpriteRenderer final : public Component {
public:
    explicit SpriteRenderer(GameObject& associated);
    SpriteRenderer(GameObject& associated, const string& file, int frameCountW = 1, int frameCountH = 1);
    void Open(const string& file);
    void SetFrameCount(int frameCountW, int frameCountH);
    void Update(float dt) override;
    void Render() override;
    void SetFrame(int frame);
private:
    Sprite sprite;
};


#endif
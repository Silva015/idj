#include "SpriteRenderer.h"

#include "GameObject.h"

SpriteRenderer::SpriteRenderer(GameObject &associated) : Component(associated) {
}

SpriteRenderer::SpriteRenderer(GameObject &associated, const string &file, const int frameCountW, const int frameCountH)
    : Component(associated), sprite(file, frameCountW, frameCountH) {
    associated.box.w = static_cast<float>(sprite.GetWidth());
    associated.box.h = static_cast<float>(sprite.GetHeight());
    SetFrame(0);
}

void SpriteRenderer::SetFrameCount(const int frameCountW, const int frameCountH) {
    sprite.SetFrameCount(frameCountW, frameCountH);
}


void SpriteRenderer::Open(const string &file) {
    sprite.Open(file);
    associated.box.w = static_cast<float>(sprite.GetWidth());
    associated.box.h = static_cast<float>(sprite.GetHeight());
}

void SpriteRenderer::SetFrame(const int frame) {
    sprite.SetFrame(frame);
}

void SpriteRenderer::Update(float dt) {
}

void SpriteRenderer::Render() {
    sprite.Render(static_cast<int>(associated.box.x), static_cast<int>(associated.box.y),
                  static_cast<int>(associated.box.w), static_cast<int>(associated.box.h));
}

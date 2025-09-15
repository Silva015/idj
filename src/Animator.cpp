#include "Animator.h"

#include "GameObject.h"
#include "SpriteRenderer.h"

Animator::Animator(GameObject &associated) : Component(associated), frameStart(0), frameEnd(0), frameTime(0),
                                             currentFrame(0), timeElapsed(0) {
}

void Animator::Update(float dt) {
    int prevCurrentFrame = currentFrame;
    if (frameTime == 0) return;
    timeElapsed += dt;
    if (timeElapsed > frameTime) {
        currentFrame++;
        timeElapsed -= frameTime;
    }
    if (currentFrame > frameEnd) currentFrame = frameStart;
    if (currentFrame != prevCurrentFrame) {
        associated.GetComponent<SpriteRenderer>()->SetFrame(currentFrame);
    }
}

void Animator::Render() {
}

void Animator::SetAnimation(const string &name) {
    const auto it = animations.find(name);
    if (it == animations.end()) return;
    const Animation animation = it->second;
    frameStart = animation.frameStart;
    frameEnd = animation.frameEnd;
    frameTime = animation.frameTime;
    currentFrame = frameStart;
    timeElapsed = 0;
    associated.GetComponent<SpriteRenderer>()->SetFrame(currentFrame);
}

void Animator::AddAnimation(const string &name, const Animation &animation) {
    const auto it = animations.find(name);
    if (it != animations.end()) return;
    animations.emplace(name, animation);
}

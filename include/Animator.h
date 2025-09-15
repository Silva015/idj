#ifndef ANIMATOR_H
#define ANIMATOR_H
#include <string>
#include <unordered_map>

#include "Animation.h"
#include "Component.h"

using namespace std;

class Animator final : public Component {
public:
    explicit Animator(GameObject& associated);
    void Update(float dt) override;
    void Render() override;
    void SetAnimation(const string& name);
    void AddAnimation(const string& name, const Animation& animation);
private:
    unordered_map<string, Animation> animations;
    int frameStart;
    int frameEnd;
    float frameTime;
    int currentFrame;
    float timeElapsed;
};

#endif
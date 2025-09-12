#ifndef STATE_H
#define STATE_H
#include "Music.h"
#include "Sprite.h"
#include <vector>
#include <memory>

#include "GameObject.h"


class State {
public:
    State();
    ~State();
    bool QuitRequested() const;
    void LoadAssets();
    void AddObject(GameObject* go);
    void Update(float dt);
    void Render() const;
private:
    Sprite bg;
    Music music;
    std::vector<std::unique_ptr<GameObject>> objectArray;
    bool quitRequested;
};

#endif
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include "Rect.h"

class Component;

class GameObject {
public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead() const;
    void RequestDelete();

    void AddComponent(Component* cpt);
    void RemoveComponent(const Component* cpt);

    template<typename T>
    T* GetComponent() {
        for (auto& cpt : components) {
            T* component = dynamic_cast<T*>(cpt);
            if (component != nullptr) {
                return component;
            }
        }
        return nullptr;
    }

    Rect box;

private:
    std::vector<Component*> components;
    bool isDead;
};

#endif
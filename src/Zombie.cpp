#include "Zombie.h"

#include "GameObject.h"
#include "SpriteRenderer.h"

Zombie::Zombie(GameObject &associated) : Component(associated), hitpoints(100) {
    auto *sr = new SpriteRenderer(associated, "../Recursos/img/Enemy.png", 3, 2);
    sr->SetFrame(1);
    associated.AddComponent(sr);
}

void Zombie::Damage(const int damage) {
    hitpoints -= damage;
    if (hitpoints <= 0) {
        auto *sr = associated.GetComponent<SpriteRenderer>();
        if (sr) {
            sr->SetFrame(5);
        }
    }
}

void Zombie::Update(const float dt) {
    Damage(1);
}

void Zombie::Render() {
}

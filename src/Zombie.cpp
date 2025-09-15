#include "Zombie.h"

#include "GameObject.h"
#include "SpriteRenderer.h"
#include "Animator.h"

Zombie::Zombie(GameObject &associated) : Component(associated), hitpoints(100) {
    auto *sr = new SpriteRenderer(associated, "../Recursos/img/Enemy.png", 3, 2);
    associated.AddComponent(sr);
    auto *animator = new Animator(associated);
    animator->AddAnimation("walking", Animation(0,3,0.1f));
    animator->AddAnimation("dead", Animation(5,5,0));
    animator->SetAnimation("walking");
    associated.AddComponent(animator);
}

void Zombie::Damage(const int damage) {
    hitpoints -= damage;
    if (hitpoints <= 0) {
        auto *animator = associated.GetComponent<Animator>();
        if (animator) {
            animator->SetAnimation("dead");
        }
    }
}

void Zombie::Update(const float dt) {
    Damage(1);
}

void Zombie::Render() {
}

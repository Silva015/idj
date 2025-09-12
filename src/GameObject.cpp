#include "GameObject.h"

#include "Component.h"

GameObject::GameObject() : isDead(false) {}

GameObject::~GameObject() {
   while (!components.empty()) {
      delete components.back();
      components.pop_back();
   }
};

void GameObject::Update(float dt) {
   for (auto& cpt : components) {
      cpt->Update(dt);
   }
}

void GameObject::Render() {
   for (auto& cpt : components) {
      cpt->Render();
   }
}

bool GameObject::IsDead() const {
   return isDead;
}

void GameObject::RequestDelete() {
   isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
   components.push_back(cpt);
}

void GameObject::RemoveComponent(const Component* cpt) {
   const auto it = std::find(components.begin(), components.end(), cpt);
   if (it != components.end()) {
      components.erase(it);
      delete cpt;
   }
}
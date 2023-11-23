#include "GameObject.h"

namespace engine = ::ores::game_engine;

engine::GameObject::~GameObject() {
    delete this->animation;
    this->animation = NULL;
}

void engine::GameObject::Update(float elapsedTime) {
    if (this->animation != NULL) {
        if (this->animation->Update(elapsedTime)) {
            delete this->animation;
            this->animation = NULL;
        }
    }
}

void engine::GameObject::OnClick(int x, int y) {}

void engine::GameObject::SetAnimation(IAnimation* animation) {
    if (this->animation != NULL) {
        delete this->animation;
    }

    this->animation = animation;
}

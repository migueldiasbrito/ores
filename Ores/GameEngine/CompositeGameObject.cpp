#include "CompositeGameObject.h"

namespace engine = ::ores::game_engine;

engine::CompositeGameObject::CompositeGameObject() {}

engine::CompositeGameObject::~CompositeGameObject() {
    int i = 0;

    for (; i < this->gameObjects.size(); ++i) {
        delete this->gameObjects[i];
        this->gameObjects[i] = NULL;
    }

    this->gameObjects.clear();
}

void engine::CompositeGameObject::AddGameObject(GameObject* gameObject) {
    if (gameObject != NULL) {
        this->gameObjects.push_back(gameObject);
    }
}

void engine::CompositeGameObject::RemoveGameObjectAfterUpdate(GameObject* gameObject) {
    if (gameObject != NULL) {
        this->gameObjectsToDeleteAfterUpdate.push_back(gameObject);
    }
}

void engine::CompositeGameObject::Draw(SDL_Renderer* renderer) {
    int i = 0;

    for (; i < this->gameObjects.size(); ++i) {
        this->gameObjects[i]->Draw(renderer);
    }
}

void engine::CompositeGameObject::Update(float elapsedTime) {
    int i = 0;

    for (; i < this->gameObjects.size(); ++i) {
        this->gameObjects[i]->Update(elapsedTime);
    }
}

void engine::CompositeGameObject::OnClick(int x, int y) {
    int i = 0;

    for (; i < this->gameObjects.size(); ++i) {
        this->gameObjects[i]->OnClick(x, y);
    }
}

void engine::CompositeGameObject::RemoveGameObjectsAfterUpdate() {
    int i = 0;
    std::vector<game_engine::GameObject*>::iterator it;

    for (; i < this->gameObjectsToDeleteAfterUpdate.size(); i++) {
        it = std::find(this->gameObjects.begin(), this->gameObjects.end(), this->gameObjectsToDeleteAfterUpdate[i]);

        if (it != this->gameObjects.end()) {
            delete *it;
            this->gameObjects.erase(it);
        }
    }

    this->gameObjectsToDeleteAfterUpdate.clear();
}

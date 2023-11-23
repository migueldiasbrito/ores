#ifndef ORES_GAMEENGINE_COMPOSITEGAMEOBJECT_H_
#define ORES_GAMEENGINE_COMPOSITEGAMEOBJECT_H_

#include "GameObject.h"
#include <vector>

namespace ores {
    namespace game_engine {
        class CompositeGameObject : public GameObject {
        public:
            //! Constructor
            CompositeGameObject();

            //! Deletes all GameObjects from composite
            virtual ~CompositeGameObject() override;

            //! Adds a GameObject to the composite
            /*!
            \param gameObject GameObject to be added
            */
            void AddGameObject(GameObject* gameObject);

            //! Adds a GameObject to be removed after the update cycle
            /*!
            \param gameObject GameObject to be removed
            */
            void RemoveGameObjectAfterUpdate(GameObject* gameObject);

            void Draw(SDL_Renderer* renderer);
            virtual void Update(float elapsedTime);
            void OnClick(int x, int y);
        protected:
            //! Array with Game Objects that form the Composite.
            std::vector<GameObject*> gameObjects;

            //! Array with Game Objects to delete after Update.
            std::vector<GameObject*> gameObjectsToDeleteAfterUpdate;

            //! Deletes configured Game Objects after Update
            void RemoveGameObjectsAfterUpdate();
        };
    }
}

#endif  // ORES_GAMEENGINE_COMPOSITEGAMEOBJECT_H_

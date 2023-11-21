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
            virtual ~CompositeGameObject();

            //! Adds a GameObject to the composite
            /*!
            \param gameObject GameObject to be added
            */
            void AddGameObject(GameObject* gameObject);

            void Draw(SDL_Renderer* renderer);
            virtual void Update(float elapsedTime);
            void OnClick(int x, int y);
        protected:
            //! Array with Game Objects that form the Composite.
            std::vector<GameObject*> gameObjects;
        };
    }
}

#endif  // ORES_GAMEENGINE_COMPOSITEGAMEOBJECT_H_

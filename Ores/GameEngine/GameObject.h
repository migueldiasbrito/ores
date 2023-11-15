#ifndef ORES_GAMEENGINE_GAMEOBJECT_H_
#define ORES_GAMEENGINE_GAMEOBJECT_H_

#include <SDL.h>

namespace ores {
    namespace game_engine {
        class GameObject {
        public:
            //! Draws the object
            /*!
            \param gRenderer SDL Renderer where to be drawn
            */
            virtual void Draw(SDL_Renderer* renderer) = 0;

            //! Updates the object
            /*!
            \param elapsedTime elapsed time since the last update
            \returns false if it should be destroyed
            */
            virtual void Update(float elapsedTime) = 0;
        };
    }
}

#endif  // ORES_GAMEENGINE_GAMEOBJECT_H_

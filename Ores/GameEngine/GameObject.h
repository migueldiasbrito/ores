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
            */
            virtual void Update(float elapsedTime) {};


            //! Handles clicks in the object
            /*!
            \param x click x coordinate
            \param y click y coordinate
            */
            virtual void OnClick(int x, int y) {};
        };
    }
}

#endif  // ORES_GAMEENGINE_GAMEOBJECT_H_

#ifndef ORES_GAMEENGINE_IMAGE_H_
#define ORES_GAMEENGINE_IMAGE_H_

#include "GameObject.h"

namespace ores {
    namespace game_engine {
        class Image : public GameObject {
        public:
            //! Deallocates the SDL_Texture
            ~Image();

            void Draw(SDL_Renderer* renderer);
        protected:
            //! Texture to be drawn
            SDL_Texture* texture = NULL;

            //! Top left corner x
            float x = 0.0f;

            //! Top left corner y
            float y = 0.0f;

            //! Object width
            float width = 0.0f;

            //! Object height
            float height = 0.0f;
        };
    }
}

#endif  // ORES_GAMEENGINE_IMAGE_H_

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
            void Update(float elapsedTime);
        protected:
            //! Texture to be drawn
            SDL_Texture* texture;

            //! Top left corner x
            float x;

            //! Top left corner y
            float y;

            //! Object width
            float width;

            //! Object height
            float height;
        };
    }
}

#endif  // ORES_GAMEENGINE_IMAGE_H_

#ifndef ORES_GAMEENGINE_BUTTON_H_
#define ORES_GAMEENGINE_BUTTON_H_

#include "CompositeGameObject.h"
#include "FontCache.h"

namespace ores {
    namespace game_engine {
        class Button : public CompositeGameObject {
        public:
            Button(SDL_Renderer* renderer, FontCache& fontCache, float x, float y, float width, float height,
                int bgRed, int bgGreen, int bgBlue, int bgAlpha, std::string fontFilename, int fontSize,
                std::string text, int textRed, int textGreen, int textBlue, int textAlpha);
        };
    }
}

#endif // ORES_GAMEENGINE_BUTTON_H_

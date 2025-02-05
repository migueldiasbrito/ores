#ifndef ORES_GAMEENGINE_TEXT_H_
#define ORES_GAMEENGINE_TEXT_H_

#include "Color.h"
#include "FontCache.h"
#include "Image.h"

namespace ores {
    namespace game_engine {
        class Text : public Image {
        public:
            //! Constructor
            /*!
            \param renderer SDL_Renderer to render the text into a texture
            \param fontCache FontCache to load the font
            \param fontFilename font filename to be loaded
            \param fontSize font size to be loaded
            \param text the text to be displayed
            \param x top left corner coordinate x
            \param y top left corner coordinate y
            \param color text color
            */
            Text(SDL_Renderer* renderer, FontCache& fontCache, std::string fontFilename, int fontSize,
                std::string text, float x, float y, Color color);

            //! Centers the text in a rectangle
            /*!
            \param x rectangle top left corner coordinate x
            \param y rectangle top left corner coordinate y
            \param width rectangle width
            \param height rectangle height
            */
            void CenterAt(float x, float y, float width, float height);
        };
    }
}

#endif  // ORES_GAMEENGINE_TEXT_H_

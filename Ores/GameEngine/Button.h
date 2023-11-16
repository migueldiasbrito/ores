#ifndef ORES_GAMEENGINE_BUTTON_H_
#define ORES_GAMEENGINE_BUTTON_H_

#include <functional>
#include "CompositeGameObject.h"
#include "FontCache.h"
#include "Rectangle.h"

namespace ores {
    namespace game_engine {
        class Button : public CompositeGameObject {
        public:
            //! Constructor
            /*!
            \param renderer SDL_Renderer to render the button text into a texture
            \param fontCache FontCache to load the button font
            \param x top left corner coordinate x
            \param y top left corner coordinate y
            \param width object width
            \param height object height
            \param bgRed button background rbga color red component
            \param bgGreen button background rbga color green component
            \param bgBlue button background rbga color blue component
            \param bgAlpha button background rbga color alpha component
            \param fontFilename font filename to be loaded
            \param fontSize font size to be loaded
            \param text the text to be displayed in the button
            \param textRed text rbga color red component
            \param textGreen text rbga color green component
            \param textBlue text rbga color blue component
            \param textAlpha text rbga color alpha component
            */
            Button(SDL_Renderer* renderer, FontCache& fontCache, float x, float y, float width, float height,
                int bgRed, int bgGreen, int bgBlue, int bgAlpha, std::string fontFilename, int fontSize,
                std::string text, int textRed, int textGreen, int textBlue, int textAlpha,
                std::function<void()> callback);

            void OnClick(int x, int y);

        private:
            //! Button clicked callback
            std::function<void()> callback = {};

            //! Returns the button rectangle background
            inline Rectangle* GetRectangle() { return (Rectangle*)this->gameObjects[0]; }
        };
    }
}

#endif // ORES_GAMEENGINE_BUTTON_H_

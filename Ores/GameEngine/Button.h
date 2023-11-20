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
            \param backgroundColor button background color
            \param fontFilename font filename to be loaded
            \param fontSize font size to be loaded
            \param text the text to be displayed in the button
            \param textColor text color
            \param callback button on click callback
            */
            Button(SDL_Renderer* renderer, FontCache& fontCache, float x, float y, float width, float height,
                Color backgroundColor, std::string fontFilename, int fontSize, std::string text, Color textColor,
                std::function<void()> callback);

            void OnClick(int x, int y);

        private:
            //! Button clicked callback
            std::function<void()> callback = {};

            //! Returns the button background rectangle
            /*!
            \return button background rectangle
            */
            inline Rectangle* GetRectangle() { return (Rectangle*)this->gameObjects[0]; }
        };
    }
}

#endif // ORES_GAMEENGINE_BUTTON_H_

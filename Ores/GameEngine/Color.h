#ifndef ORES_GAMEENGINE_COLOR_H_
#define ORES_GAMEENGINE_COLOR_H_

#include <SDL.h>

namespace ores {
    namespace game_engine {
        class Color
        {
        public:
            //! Empty Constructor (Black)
            Color();

            //! Constructor
            /*!
            \param red red component
            \param green green component
            \param blue blue component
            */
            Color(int red, int green, int blue);

            //! Constructor with transparency
            /*!
            \param red red component
            \param green green component
            \param blue blue component
            \param alpha alpha component
            */
            Color(int red, int green, int blue, int alpha);

            //! Converts Color to SDL_Color
            inline SDL_Color ToSdlColor() { SDL_Color color = { red, green, blue, alpha }; return color; }

            //! Red component
            int red = 0x00;

            //! Green component
            int green = 0x00;

            //! Blue component
            int blue = 0x00;

            //! Aplha component
            int alpha = 0xFF;
        };
    }
}

#endif // ORES_GAMEENGINE_COLOR_H_

#ifndef ORES_GAMEENGINE_RECTANGLE_H_
#define ORES_GAMEENGINE_RECTANGLE_H_

#include "GameObject.h"

namespace ores {
    namespace game_engine {
        class Rectangle : public GameObject {
        public:
            //! Constructor
            /*!
            \param x top left corner coordinate x
            \param y top left corner coordinate y
            \param width object width
            \param height object height
            \param red rbga color red component
            \param green rbga color green component
            \param blue rbga color blue component
            \param alpha rbga color alpha component
            */
            Rectangle(float x, float y, float width, float height, int red, int green, int blue, int alpha);

            //! Returns Rectangle x coordinate
            /*!
            \return Rectangle x coordinate
            */
            inline float GetX() { return this->x; }

            //! Returns Rectangle y coordinate
            /*!
            \return Rectangle y coordinate
            */
            inline float GetY() { return this->y; }

            //! Returns Rectangle width
            /*!
            \return Rectangle width
            */
            inline float GetWidth() { return this->width; }

            //! Returns Rectangle height
            /*!
            \return Rectangle height
            */
            inline float GetHeight() { return this->height; }

            void Draw(SDL_Renderer* renderer);
        private:
            //! Top left corner x
            float x = 0.0f;

            //! Top left corner y
            float y = 0.0f;

            //! Object width
            float width = 0.0f;

            //! Object height
            float height = 0.0f;

            //! Object rgba color red component
            int red = 0x00;

            //! Object rgba color green component
            int green = 0x00;

            //! Object rgba color blue component
            int blue = 0x00;

            //! Object rgba color alpha component
            int alpha = 0x00;
        };
    }
}

#endif  // ORES_GAMEENGINE_RECTANGLE_H_

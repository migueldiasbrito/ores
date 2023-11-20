#ifndef ORES_GAMEENGINE_RECTANGLE_H_
#define ORES_GAMEENGINE_RECTANGLE_H_

#include "Color.h"
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
            \param color object color
            */
            Rectangle(float x, float y, float width, float height, Color color);

            //! Returns Rectangle left x coordinate
            /*!
            \return Rectangle lefy x coordinate
            */
            inline float GetLeft() { return this->x; }

            //! Returns Rectangle top y coordinate
            /*!
            \return Rectangle top y coordinate
            */
            inline float GetTop() { return this->y; }

            //! Returns Rectangle right x coordinate
            /*!
            \return Rectangle right x coordinate
            */
            inline float GetRight() { return this->x + this->width; }

            //! Returns Rectangle bottom y coordinate
            /*!
            \return Rectangle bottom y coordinate
            */
            inline float GetBottom() { return this->y + this->height; }

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
            Color color = Color();
        };
    }
}

#endif  // ORES_GAMEENGINE_RECTANGLE_H_

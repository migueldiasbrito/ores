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

            //! Checks if point is inside rectangle
            /*!
            \param x point x coordinate
            \param y point y coordinate
            */
            bool Intersects(float x, float y) {
                return x >= this->x && x <= this->x + this->width && y >= this->y && y <= this->y + this->height;
            }

            //! Updates rectangle width
            /*!
            \param width new width
            */
            void SetWidth(float width);

            //! Updates rectangle height
            /*!
            \param width new height
            */
            void SetHeight(float height);

            void Draw(SDL_Renderer* renderer);

        protected:
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

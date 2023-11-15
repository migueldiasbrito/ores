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

			void Draw(SDL_Renderer* renderer);
			void Update(float elapsedTime);
		private:
			//! Top left corner x
			float x;

			//! Top left corner y
			float y;

			//! Object width
			float width;

			//! Object height
			float height;

			//! Object rgba color red component
			int red;

			//! Object rgba color green component
			int green;

			//! Object rgba color blue component
			int blue;

			//! Object rgba color alpha component
			int alpha;
        };
    }
}

#endif  // ORES_GAMEENGINE_RECTANGLE_H_

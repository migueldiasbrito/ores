#ifndef ORES_PRESENTATION_BOXFALLANIMATION_H_
#define ORES_PRESENTATION_BOXFALLANIMATION_H_

#include "../GameEngine/IAnimation.h"
#include "../GameEngine/Rectangle.h"

namespace ores {
    namespace presentation {
        class BoxMoveAnimation : public game_engine::IAnimation {
        public:
            //! Constructor
            /*!
            \param target game object to animate
            \param finalX box final x coordinate
            \param finalY box final y coordinate
            \param durantion animation duration
            */ 
            BoxMoveAnimation(game_engine::Rectangle* target, float finalX, float finalY, float duration);

            bool Update(float elapsedTime);
        private:
            //! game object to animate
            game_engine::Rectangle* target = NULL;

            //! box initial x coordinate
            float initialX = 0.0f;

            //! box initial y coordinate
            float initialY = 0.0f;

            //! box final x coordinate
            float finalX = 0.0f;

            //! box final y coordinate
            float finalY = 0.0f;

            //! animation elapsed time
            float elapsedTime = 0.0f;

            //! animation duration
            float duration = 0.0f;
        };
    }
}

#endif // ORES_PRESENTATION_BOXFALLANIMATION_H_

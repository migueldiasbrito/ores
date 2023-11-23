#ifndef ORES_PRESENTATION_BOXDISAPPEARANIMATION_H_
#define ORES_PRESENTATION_BOXDISAPPEARANIMATION_H_

#include "../GameEngine/IAnimation.h"
#include "../GameEngine/Rectangle.h"
#include <functional>

namespace ores {
    namespace presentation {
        class BoxDisappearAnimation : public game_engine::IAnimation {
        public:
            //! Constructor
            /*!
            \param target game object to animate
            \param durantion animation duration
            \param callback method to be called on animation end
            */
            BoxDisappearAnimation(game_engine::Rectangle* target, float duration, std::function<void()> callback);

            bool Update(float elapsedTime);
        private:
            //! game object to animate
            game_engine::Rectangle* target = NULL;

            //! animation elapsed time
            float elapsedTime = 0.0f;

            //! animation duration
            float duration = 0.0f;

            //! Callback to be called when time reaches 0
            std::function<void()> callback;
        };
    }
}

#endif // ORES_PRESENTATION_BOXDISAPPEARANIMATION_H_

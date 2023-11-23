#ifndef ORES_PRESENTATION_TIMERUIDISPLAY_H_
#define ORES_PRESENTATION_TIMERUIDISPLAY_H_

#include "../GameEngine/Color.h"
#include "../GameEngine/CompositeGameObject.h"
#include <functional>

namespace ores {
    namespace presentation {
        class TimerUiDisplay : public game_engine::CompositeGameObject {
        public:
            //! Constructor
            /*!
            \param x top left corner coordinate x
            \param y top left corner coordinate y
            \param width object width
            \param height object height
            \param borderColor color for the timer border
            \param backgroundColor bar background color
            \param timerColor timer bar color
            \param time seconds to trigger callback
            \param callback method to be called after time
            */
            TimerUiDisplay(float x, float y, float width, float height, game_engine::Color borderColor,
                game_engine::Color backgroundColor, game_engine::Color timerColor, float time,
                std::function<void()> callback);

            //! Stops the timer
            void StopTimer();

            void Update(float elapsedTime);
        private:
            //! Initial time
            float initialTime = 0.0f;

            //! Current time until callback is called
            float currentTime = 0.0f;

            //! Maximum inner rectangle width
            float maxTimerWidth = 0.0f;

            //! Controls if timer is running
            bool timerRunning = false;

            //! Callback to be called when time reaches 0
            std::function<void()> callback;
        };
    }
}

#endif // ORES_PRESENTATION_TIMERUIDISPLAY_H_

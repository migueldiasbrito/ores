#ifndef ORES_GAMEENGINE_IANIMATION_H_
#define ORES_GAMEENGINE_IANIMATION_H_

namespace ores {
    namespace game_engine {
        class IAnimation {
        public:
            //! Updates the animation
            /*!
            \param elapsedTime time since last Update
            \return true if animation is done
            */
            virtual bool Update(float elapsedTime) = 0;
        };
    }
}

#endif  // ORES_GAMEENGINE_IANIMATION_H_

#ifndef ORES_PRESENTATION_CONFIG_H_
#define ORES_PRESENTATION_CONFIG_H_

#include "../GameEngine/Color.h"

namespace ores {
    namespace presentation {
        static class Config
        {
        public:
            //! Total number of columns
            inline static game_engine::Color GetColor(int colorCode) { return colors[colorCode]; }

        private:
            static const game_engine::Color colors[];
        };
    }
}

#endif // ORES_PRESENTATION_CONFIG_H_

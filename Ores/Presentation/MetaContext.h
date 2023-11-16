#ifndef ORES_PRESENTATION_METACONTEXT_H_
#define ORES_PRESENTATION_METACONTEXT_H_

#include "../GameEngine/CompositeGameObject.h"
#include "../GameEngine/Engine.h"
#include "../GameEngine/FontCache.h"

namespace ores {
    namespace presentation {
        class MetaContext : public game_engine::CompositeGameObject {
        public:
            //! Constructor
            /*!
            \param engine Game engine where context is drawn
            \param fontCache FontCache to load fonts
            */
            MetaContext(game_engine::Engine &engine, game_engine::FontCache &fontCache);
        };
    }
}

#endif // ORES_PRESENTATION_METACONTEXT_H_

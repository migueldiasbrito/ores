#ifndef ORES_PRESENTATION_GAMECONTEXT_H_
#define ORES_PRESENTATION_GAMECONTEXT_H_

#include "../Data/IGridDataReader.h"
#include "../GameEngine/CompositeGameObject.h"
#include "../GameEngine/Engine.h"
#include "../GameEngine/FontCache.h"
#include "../Observers/IGameOverObserver.h"
#include "../Services/IGridService.h"

namespace ores {
    namespace presentation {
        class GameContext : public game_engine::CompositeGameObject, observers::IGameOverObserver {
        public:
            //! Constructor
            /*!
            \param engine Game engine where context is drawn
            \param fontCache FontCache to load fonts
            */
            GameContext(game_engine::Engine& engine, game_engine::FontCache& fontCache);

            //! Detaches observer from service
            virtual ~GameContext();

            void OnGameOver();
        private:
            //! the grid data reader
            data::IGridDataReader* gridDataReader;

            //! the grid service
            services::IGridService* gridService;

            //! Engine
            game_engine::Engine* engine;

            //! FontCache
            game_engine::FontCache* fontCache;
        };
    }
}

#endif // ORES_PRESENTATION_GAMECONTEXT_H_

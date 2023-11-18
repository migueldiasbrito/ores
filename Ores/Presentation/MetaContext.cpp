#include "MetaContext.h"
#include "GameContext.h"
#include "../GameEngine/Button.h"
#include "../Services/IGridService.h"
#include "../Services/ServiceLocator.h"

namespace presentation = ::ores::presentation;

presentation::MetaContext::MetaContext(game_engine::Engine& engine, game_engine::FontCache& fontCache) {
    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, 0, 0, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF,
        "../../Resources/Fonts/consola.ttf", 28, "PLAY", 0x00, 0x00, 0x00, 0xFF,
        [&engine, &fontCache, this] {
            services::ServiceLocator::GetService<services::IGridService>()->StartGame();
            engine.LoadScene(new GameContext(engine, fontCache));
        }));

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, 0, 300, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF,
        "../../Resources/Fonts/consola.ttf", 28, "QUIT", 0x00, 0x00, 0x00, 0xFF, [&engine] { engine.StopLoop(); }));
}

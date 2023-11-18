#include "MetaContext.h"
#include "GameContext.h"
#include "../GameEngine/Button.h"

namespace presentation = ::ores::presentation;
namespace engine = ::ores::game_engine;

presentation::MetaContext::MetaContext(engine::Engine& engine, engine::FontCache& fontCache) {
    AddGameObject(new engine::Button(engine.GetRenderer(), fontCache, 0, 0, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF,
        "../../Resources/Fonts/consola.ttf", 28, "PLAY", 0x00, 0x00, 0x00, 0xFF, [&engine, &fontCache] { engine.LoadScene(new GameContext(engine, fontCache)); }));

    AddGameObject(new engine::Button(engine.GetRenderer(), fontCache, 0, 300, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF,
        "../../Resources/Fonts/consola.ttf", 28, "QUIT", 0x00, 0x00, 0x00, 0xFF, [&engine] { engine.StopLoop(); }));
}

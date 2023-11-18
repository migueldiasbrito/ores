#include "GameContext.h"
#include "MetaContext.h"
#include "../GameEngine/Button.h"

namespace presentation = ::ores::presentation;
namespace engine = ::ores::game_engine;

presentation::GameContext::GameContext(engine::Engine& engine, engine::FontCache& fontCache) {
    AddGameObject(new engine::Button(engine.GetRenderer(), fontCache, 300, 0, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF,
        "../../Resources/Fonts/consola.ttf", 28, "QUIT", 0x00, 0x00, 0x00, 0xFF, [&engine, &fontCache] { engine.LoadScene(new MetaContext(engine, fontCache)); }));
}

#include "MetaContext.h"
#include "GameContext.h"
#include "../GameEngine/Button.h"
#include "../GameEngine/Text.h"
#include "../Services/IGridService.h"
#include "../Services/ServiceLocator.h"

namespace presentation = ::ores::presentation;

presentation::MetaContext::MetaContext(game_engine::Engine& engine, game_engine::FontCache& fontCache) {
    int windowWidth;
    int windowHeight;
    engine.GetResolution(windowWidth, windowHeight);

    game_engine::Text* text = new game_engine::Text(engine.GetRenderer(), fontCache,
        "../../Resources/Fonts/consola.ttf", 72, "ORES", 0, 0, game_engine::Color(0xFF, 0x00, 0x00));
    text->CenterAt(0, 0, windowWidth, windowHeight / 2.0f);
    AddGameObject(text);

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, windowWidth / 2.0f - 200,
        windowHeight / 2.0f, 400, 100, game_engine::Color(0xFF, 0xFF, 0xFF), "../../Resources/Fonts/consola.ttf", 28,
        "PLAY", game_engine::Color(0x00, 0x00, 0x00), [&engine, &fontCache, this] {
            services::ServiceLocator::GetService<services::IGridService>()->StartGame();
            engine.LoadScene(new GameContext(engine, fontCache));
        }));

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, windowWidth / 2.0f - 200,
        windowHeight / 2.0f + 150, 400, 100, game_engine::Color(0xFF, 0xFF, 0xFF), "../../Resources/Fonts/consola.ttf",
        28, "QUIT", game_engine::Color(0x00, 0x00, 0x00), [&engine] { engine.StopLoop(); }));
}

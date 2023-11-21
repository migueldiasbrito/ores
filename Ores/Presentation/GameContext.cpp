#include "GameContext.h"
#include "../Data/DataReaders.h"
#include "../GameEngine/Button.h"
#include "../Services/ServiceLocator.h"
#include "GridUiDisplay.h"
#include "MetaContext.h"

namespace presentation = ::ores::presentation;

presentation::GameContext::GameContext(game_engine::Engine& engine, game_engine::FontCache& fontCache)
    : gridDataReader(data::DataReaders::GetDataReader<data::IGridDataReader>())
    , gridService(services::ServiceLocator::GetService<services::IGridService>()) {

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, 300, 0, 400, 100,
        game_engine::Color(0xFF, 0xFF, 0xFF), "../../Resources/Fonts/consola.ttf", 28, "MAIN MENU",
        game_engine::Color(0x00, 0x00, 0x00),
        [&engine, &fontCache] { engine.LoadScene(new MetaContext(engine, fontCache)); }));

    AddGameObject(new GridUiDisplay(this->gridDataReader, this->gridService));
}

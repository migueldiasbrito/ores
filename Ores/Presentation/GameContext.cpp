#include "GameContext.h"
#include "../Data/Balancing.h"
#include "../Data/DataReaders.h"
#include "../GameEngine/Button.h"
#include "../Services/ServiceLocator.h"
#include "BoxUiDisplay.h"
#include "MetaContext.h"

namespace presentation = ::ores::presentation;

presentation::GameContext::GameContext(game_engine::Engine& engine, game_engine::FontCache& fontCache)
    : gridDataReader(data::DataReaders::GetDataReader<data::IGridDataReader>())
    , gridService(services::ServiceLocator::GetService<services::IGridService>()) {
    data::IBox* box;
    int column = 0;
    int row = 0;

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, 300, 0, 400, 100,
        game_engine::Color(0xFF, 0xFF, 0xFF), "../../Resources/Fonts/consola.ttf", 28, "MAIN MENU",
        game_engine::Color(0x00, 0x00, 0x00),
        [&engine, &fontCache] { engine.LoadScene(new MetaContext(engine, fontCache)); }));

    for (; column < data::Balancing::COLUMN_COUNT; ++column) {
        for (row = 0; row < data::Balancing::ROW_COUNT; row++) {
            box = this->gridDataReader->GetBoxAt(column, row);
            if (box != NULL) {
                AddGameObject(new BoxUiDisplay(box, this->gridService));
            }
        }
    }
}

#include "GameContext.h"
#include "../Data/Balancing.h"
#include "../Data/DataReaders.h"
#include "../Data/IGridDataReader.h"
#include "../GameEngine/Button.h"
#include "Config.h"
#include "MetaContext.h"

namespace presentation = ::ores::presentation;

presentation::GameContext::GameContext(game_engine::Engine& engine, game_engine::FontCache& fontCache) {
    data::IGridDataReader* gridDataReader = data::DataReaders::GetDataReader<data::IGridDataReader>();
    data::Box* box;
    int column = 0;
    int row = 0;

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, 300, 0, 400, 100,
        game_engine::Color(0xFF, 0xFF, 0xFF), "../../Resources/Fonts/consola.ttf", 28, "MAIN MENU",
        game_engine::Color(0x00, 0x00, 0x00),
        [&engine, &fontCache] { engine.LoadScene(new MetaContext(engine, fontCache)); }));

    for (; column < data::Balancing::COLUMN_COUNT; ++column) {
        for (row = 0; row < data::Balancing::ROW_COUNT; row++) {
            box = gridDataReader->GetBoxAt(column, row);
            if (box != NULL) {
                AddGameObject(new game_engine::Rectangle(100 + 100 * column, 1100 - 100 * row, 100, 100,
                    Config::GetColor(box->GetColor())));
            }
        }
    }
}

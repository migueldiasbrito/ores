#include "GameContext.h"
#include "MetaContext.h"
#include "../GameEngine/Button.h"
#include "../Data/IGridDataReader.h"
#include "../Data/DataReaders.h"

namespace presentation = ::ores::presentation;

// Add Color class to game_engine
// Create some kind of config
void GetColors(int colorId, int& red, int& green, int& blue) {
    switch (colorId)
    {
    case 0:
        red = 0xFF;
        green = 0x00;
        blue = 0x00;
        break;
    case 1:
        red = 0x00;
        green = 0xFF;
        blue = 0x00;
        break;
    case 2:
        red = 0x00;
        green = 0x00;
        blue = 0xFF;
        break;
    case 3:
        red = 0xFF;
        green = 0xFF;
        blue = 0x00;
        break;
    case 4:
        red = 0xFF;
        green = 0x00;
        blue = 0xFF;
        break;
    default:
        red = 0xFF;
        green = 0xFF;
        blue = 0xFF;
        break;
    }
}

presentation::GameContext::GameContext(game_engine::Engine& engine, game_engine::FontCache& fontCache) {
    data::IGridDataReader* gridDataReader = data::DataReaders::GetDataReader<data::IGridDataReader>();
    std::vector<std::vector<data::Box*>> grid = gridDataReader->GetBoxes();
    // change to [column][row]
    int i = 0;
    int j = 0;
    int red, green, blue;

    AddGameObject(new game_engine::Button(engine.GetRenderer(), fontCache, 300, 0, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF,
        "../../Resources/Fonts/consola.ttf", 28, "MAIN MENU", 0x00, 0x00, 0x00, 0xFF, [&engine, &fontCache] { engine.LoadScene(new MetaContext(engine, fontCache)); }));

    // will need a remove GameObject
    // box will need some kind of id
    for (; i < grid.size(); ++i) {
        for (j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] != NULL) {
                GetColors(grid[i][j]->GetColor(), red, green, blue);
                AddGameObject(new game_engine::Rectangle(100 + 100 * j, 1100 - 100 * i, 100, 100, red, green, blue, 0xFF));
            }
        }
    }
}

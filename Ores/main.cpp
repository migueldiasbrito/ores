#include "Data/DataReaders.h"
#include "Data/GridModel.h"
//#include "GameEngine/Button.h"
#include "GameEngine/Engine.h"
#include "GameEngine/FontCache.h"
//#include "GameEngine/Rectangle.h"
//#include "GameEngine/Text.h"
#include "Presentation/MetaContext.h"
#include "Services/ServiceLocator.h"
#include "Services/GridService.h"
#include <time.h>

int main(int argc, char* args[])
{
    ores::game_engine::Engine engine;
    ores::game_engine::FontCache fontCache;
    ores::data::GridModel gridModel;
    ores::services::GridService gridService(&gridModel);

    srand(time(NULL));

    ores::data::DataReaders::AddDataReader<ores::data::IGridDataReader>(&gridModel);
    ores::services::ServiceLocator::AddService<ores::services::IGridService>(&gridService);

    engine.Init();

    //engine.AddGameObject(new ores::game_engine::Rectangle(0, 0, 100, 100, 0xFF, 0xFF, 0xFF, 0xFF));
    //engine.AddGameObject(new ores::game_engine::Text(engine.GetRenderer(), fontCache, "../../Resources/Fonts/consola.ttf", 28, "Le Text", 200, 200, 0xFF, 0xFF, 0xFF, 0xFF));
    //engine.AddGameObject(new ores::game_engine::Button(engine.GetRenderer(), fontCache, 0, 0, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF, "../../Resources/Fonts/consola.ttf", 28, "Le Text", 0x00, 0x00, 0x00, 0xFF, [&engine] { engine.StopLoop(); }));
    engine.LoadScene(new ores::presentation::MetaContext(engine, fontCache));

    engine.Loop();

    engine.Close();

    return 0;
}

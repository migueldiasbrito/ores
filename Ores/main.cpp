#include "GameEngine/Button.h"
#include "GameEngine/Engine.h"
#include "GameEngine/FontCache.h"
//#include "GameEngine/Rectangle.h"
//#include "GameEngine/Text.h"

int main(int argc, char* args[])
{
    ores::game_engine::Engine engine;
    ores::game_engine::FontCache fontCache;

    engine.Init();

    //engine.AddGameObject(new ores::game_engine::Rectangle(0, 0, 100, 100, 0xFF, 0xFF, 0xFF, 0xFF));
    //engine.AddGameObject(new ores::game_engine::Text(engine.GetRenderer(), fontCache, "../../Resources/Fonts/consola.ttf", 28, "Le Text", 200, 200, 0xFF, 0xFF, 0xFF, 0xFF));
    engine.AddGameObject(new ores::game_engine::Button(engine.GetRenderer(), fontCache, 0, 0, 400, 100, 0xFF, 0xFF, 0xFF, 0xFF, "../../Resources/Fonts/consola.ttf", 28, "Le Text", 0x00, 0x00, 0x00, 0xFF, [&engine] { engine.StopLoop(); }));

    engine.Loop();

    engine.Close();

    return 0;
}

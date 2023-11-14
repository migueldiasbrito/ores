#include "GameEngine/Engine.h"
#include "GameEngine/Rectangle.h"

int main(int argc, char* args[])
{
	ores::game_engine::Engine engine;

	engine.Init();

	engine.AddGameObject(new ores::game_engine::Rectangle(0, 0, 100, 100, 0xFF, 0xFF, 0xFF, 0xFF));

	engine.Loop();

	engine.Close();

	return 0;
}

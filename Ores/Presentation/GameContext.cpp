#include "GameContext.h"
#include "../Data/Balancing.h"
#include "../Data/DataReaders.h"
#include "../GameEngine/Button.h"
#include "../GameEngine/Text.h"
#include "../Services/ServiceLocator.h"
#include "GridUiDisplay.h"
#include "MetaContext.h"
#include "TimerUiDisplay.h"

namespace presentation = ::ores::presentation;

presentation::GameContext::GameContext(game_engine::Engine& engine, game_engine::FontCache& fontCache)
    : gridDataReader(data::DataReaders::GetDataReader<data::IGridDataReader>())
    , gridService(services::ServiceLocator::GetService<services::IGridService>()), engine(&engine), fontCache(&fontCache) {
    int windowWidth;
    int windowHeight;
    services::IGridService* gridService = this->gridService;

    this->engine->GetResolution(windowWidth, windowHeight);

    AddGameObject(new game_engine::Button(this->engine->GetRenderer(), *this->fontCache, windowWidth - 400 - 10, 10,
        400, 100, game_engine::Color(0xFF, 0xFF, 0xFF), "../../Resources/Fonts/consola.ttf", 28, "MAIN MENU",
        game_engine::Color(0x00, 0x00, 0x00),
        [this] { this->engine->LoadScene(new MetaContext(*this->engine, *this->fontCache)); }));

    AddGameObject(new GridUiDisplay(this->gridDataReader, this->gridService, windowWidth, windowHeight));

    AddGameObject(new TimerUiDisplay(windowWidth / 2.0f - 250, 100, 500, 75, game_engine::Color(0xFF, 0xFF, 0xFF),
        game_engine::Color(0x00, 0x00, 0x00), game_engine::Color(0xFF, 0xFF, 0xFF), data::Balancing::NEW_COLUMN_TIME,
        [gridService] { gridService->InsertNewColumn(); }));

    this->gridService->AttachGameOverObserver(this);
}

presentation::GameContext::~GameContext() {
    this->gridService->DettachGameOverObserver(this);
}

void presentation::GameContext::OnGameOver() {
    int windowWidth;
    int windowHeight;

    ((TimerUiDisplay*)this->gameObjects[2])->StopTimer();

    game_engine::Text* text = new game_engine::Text(this->engine->GetRenderer(), *this->fontCache,
        "../../Resources/Fonts/consola.ttf", 72, "GAME OVER", 0, 0, game_engine::Color(0xFF, 0x00, 0x00));
    this->engine->GetResolution(windowWidth, windowHeight);
    text->CenterAt(0, 0, windowWidth, windowHeight);
    AddGameObject(text);
}

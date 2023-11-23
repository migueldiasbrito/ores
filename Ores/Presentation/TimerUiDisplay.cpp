#include "TimerUiDisplay.h"
#include "../GameEngine/Rectangle.h"

namespace presentation = ::ores::presentation;

presentation::TimerUiDisplay::TimerUiDisplay(float x, float y, float width, float height, 
    game_engine::Color borderColor, game_engine::Color backgroundColor, game_engine::Color timerColor, float time,
    std::function<void()> callback)
    : initialTime(time), currentTime(time), maxTimerWidth(width - 8),callback(callback), timerRunning(true) {
    AddGameObject(new game_engine::Rectangle(x, y, width, height, borderColor));
    AddGameObject(new game_engine::Rectangle(x + 2, y + 2, width - 4, height - 4, backgroundColor));
    AddGameObject(new game_engine::Rectangle(x + 4, y + 4, width - 8, height - 8, timerColor));
}

void presentation::TimerUiDisplay::StopTimer() {
    this->timerRunning = false;
}

void presentation::TimerUiDisplay::Update(float elapsedTime) {
    CompositeGameObject::Update(elapsedTime);
    if (!this->timerRunning) return;

    this->currentTime -= elapsedTime;

    if (this->currentTime <= 0) {
        this->callback();
        this->currentTime += this->initialTime;
    }

    ((game_engine::Rectangle*) this->gameObjects[2])->SetWidth(
        this->maxTimerWidth * this->currentTime / this->initialTime);
}

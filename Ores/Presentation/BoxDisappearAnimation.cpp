#include "BoxDisappearAnimation.h"

namespace presentation = ::ores::presentation;

presentation::BoxDisappearAnimation::BoxDisappearAnimation(game_engine::Rectangle* target, float duration,
    std::function<void()> callback) : target(target), elapsedTime(0), duration(duration), callback(callback) {}

bool presentation::BoxDisappearAnimation::Update(float elapsedTime) {
    this->elapsedTime += elapsedTime;
    int deltaAlpha;

    if (this->elapsedTime >= duration) {
        this->target->SetAlpha(0x00);
        callback();
        return true;
    }
    else {
        deltaAlpha = 0xFF - this->elapsedTime / this->duration * 0xFF;

        this->target->SetAlpha(deltaAlpha);
        return false;
    }
}

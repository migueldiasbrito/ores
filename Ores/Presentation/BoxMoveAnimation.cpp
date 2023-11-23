#include "BoxMoveAnimation.h"

namespace presentation = ::ores::presentation;

presentation::BoxMoveAnimation::BoxMoveAnimation(game_engine::Rectangle* target, float finalX, float finalY,
    float duration) : target(target), initialX(target->GetX()), initialY(target->GetY()), finalX(finalX),
    finalY(finalY), elapsedTime(0), duration(duration) {}

bool presentation::BoxMoveAnimation::Update(float elapsedTime) {
    this->elapsedTime += elapsedTime;
    float deltaX;
    float deltaY;

    if (this->elapsedTime >= duration) {
        this->target->SetX(this->finalX);
        this->target->SetY(this->finalY);
        return true;
    }
    else {
        deltaX = this->initialX + this->elapsedTime / this->duration * (this->finalX - this->initialX);
        deltaY = this->initialY + this->elapsedTime / this->duration * (this->finalY - this->initialY);

        this->target->SetX(deltaX);
        this->target->SetY(deltaY);
        return false;
    }
}

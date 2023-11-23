#include "BoxUiDisplay.h"
#include "BoxMoveAnimation.h"
#include "Config.h"

namespace presentation = ::ores::presentation;

presentation::BoxUiDisplay::BoxUiDisplay(data::IBox* box, services::IGridService* gridService, float xCoordOnZero,
    float yCoordOnZero, float boxDimention, float initialXOffset, float initialYOffset)
    : box(box), gridService(gridService), xCoordOnZero(xCoordOnZero), yCoordOnZero(yCoordOnZero),
    Rectangle(xCoordOnZero + boxDimention * box->GetColumn(), yCoordOnZero - boxDimention * box->GetRow(),
        boxDimention, boxDimention, Config::GetColor(box->GetColor())) {
    box->AttachBoxPositionUpdatedObserver(this);

    if (initialXOffset != 0 || initialYOffset != 0) {
        this->SetX(x + initialXOffset);
        this->SetY(y + initialYOffset);

        this->SetAnimation(new BoxMoveAnimation(this, this->x - initialXOffset, this->y - initialYOffset, 1.0f));
    }
}

void presentation::BoxUiDisplay::OnClick(int x, int y) {
    if (Intersects(x, y)) {
        this->gridService->TryPopBoxAt(this->box->GetColumn(), this->box->GetRow());
    }
}

void presentation::BoxUiDisplay::OnBoxPositionUpdated(int column, int row) {
    float x = this->xCoordOnZero + this->width * column;
    float y = this->yCoordOnZero - this->height * row;

    this->SetAnimation(new BoxMoveAnimation(this, x, y, 0.5f));
}

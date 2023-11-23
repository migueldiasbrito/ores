#include "BoxUiDisplay.h"
#include "Config.h"

namespace presentation = ::ores::presentation;

presentation::BoxUiDisplay::BoxUiDisplay(data::IBox* box, services::IGridService* gridService, float xCoordOnZero,
    float yCoordOnZero, float boxDimention)
    : box(box), gridService(gridService), xCoordOnZero(xCoordOnZero), yCoordOnZero(yCoordOnZero),
    Rectangle(xCoordOnZero + boxDimention * box->GetColumn(), yCoordOnZero - boxDimention * box->GetRow(),
        boxDimention, boxDimention, Config::GetColor(box->GetColor())) {
    box->AttachBoxPositionUpdatedObserver(this);
}

void presentation::BoxUiDisplay::OnClick(int x, int y) {
    if (Intersects(x, y)) {
        this->gridService->TryPopBoxAt(this->box->GetColumn(), this->box->GetRow());
    }
}

void presentation::BoxUiDisplay::OnBoxPositionUpdated(int column, int row) {
    this->x = this->xCoordOnZero + this->width * column;
    this->y = this->yCoordOnZero - this->height * row;
}

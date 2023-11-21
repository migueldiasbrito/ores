#include "BoxUiDisplay.h"
#include "Config.h"

namespace presentation = ::ores::presentation;

presentation::BoxUiDisplay::BoxUiDisplay(data::IBox* box, services::IGridService* gridService) : box(box), gridService(gridService),
    Rectangle(100 + 100 * box->GetColumn(), 1100 - 100 * box->GetRow(), 100, 100, Config::GetColor(box->GetColor())) {
    box->AttachBoxPositionUpdatedObserver(this);
}

void presentation::BoxUiDisplay::OnClick(int x, int y) {
    if (Intersects(x, y)) {
        this->gridService->TryPopBoxAt(this->box->GetColumn(), this->box->GetRow());
    }
}

void presentation::BoxUiDisplay::OnBoxPositionUpdated(int column, int row) {
    this->x = 100 + 100 * column;
    this->y = 1100 - 100 * row;
}

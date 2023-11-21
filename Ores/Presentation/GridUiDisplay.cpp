#include "GridUiDisplay.h"
#include "../Data/Balancing.h"

namespace presentation = ::ores::presentation;

presentation::GridUiDisplay::GridUiDisplay(data::IGridDataReader* gridDataReader, services::IGridService* gridService)
    : gridDataReader(gridDataReader), gridService(gridService) {
    data::IBox* box;
    BoxUiDisplay* boxDisplay;
    int column = 0;
    int row = 0;

    for (; column < data::Balancing::COLUMN_COUNT; ++column) {
        for (row = 0; row < data::Balancing::ROW_COUNT; row++) {
            box = this->gridDataReader->GetBoxAt(column, row);
            if (box != NULL) {
                boxDisplay = new BoxUiDisplay(box, this->gridService);
                AddGameObject(boxDisplay);
                this->boxesById.insert(std::pair<int, BoxUiDisplay*>(box->GetId(), boxDisplay));
            }
        }
    }

    this->gridService->AttachBoxesPoppedObserver(this);
}

presentation::GridUiDisplay::~GridUiDisplay() {
    this->gridService->DettachBoxesPoppedObserver(this);
}

void presentation::GridUiDisplay::OnBoxesPopped(std::vector<int> boxesPoppedIds) {
    int i = 0;
    std::map<int, BoxUiDisplay*>::iterator boxMapIt;
    std::vector<game_engine::GameObject*>::iterator goIt;

    for (; i < boxesPoppedIds.size(); ++i) {
        boxMapIt = this->boxesById.find(boxesPoppedIds[i]);

        if (boxMapIt == this->boxesById.end()) continue;

        goIt = std::find(this->gameObjects.begin(), this->gameObjects.end(), boxMapIt->second);

        if (goIt != this->gameObjects.end()) {
            this->gameObjects.erase(goIt);
        }

        delete boxMapIt->second;
        this->boxesById.erase(boxMapIt);
    }
}

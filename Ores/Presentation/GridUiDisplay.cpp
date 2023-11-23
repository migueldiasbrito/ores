#include "GridUiDisplay.h"
#include "../Data/Balancing.h"
#include "BoxDisappearAnimation.h"

namespace presentation = ::ores::presentation;

presentation::GridUiDisplay::GridUiDisplay(data::IGridDataReader* gridDataReader, services::IGridService* gridService,
    float width, float height) : gridDataReader(gridDataReader), gridService(gridService) {
    data::IBox* box;
    BoxUiDisplay* boxDisplay;
    int column = 0;
    int row = 0;

    this->boxDimention = width > 1000 && height > 1000 ? 100
        : width> 500 && height> 500 ? 50
        : 10;

    this->gridXCoord = width / 2.0f - data::Balancing::COLUMN_COUNT / 2.0f * this->boxDimention;
    this->gridYCoord = height / 2.0f + data::Balancing::ROW_COUNT / 2.0f * this->boxDimention;

    this->newBoxYOffset = - this->gridYCoord;

    for (; column < data::Balancing::COLUMN_COUNT; ++column) {
        for (row = 0; row < data::Balancing::ROW_COUNT; row++) {
            box = this->gridDataReader->GetBoxAt(column, row);
            if (box != NULL) {
                boxDisplay = new BoxUiDisplay(box, this->gridService, this->gridXCoord, this->gridYCoord,
                    this->boxDimention);
                AddGameObject(boxDisplay);
                this->boxesById.insert(std::pair<int, BoxUiDisplay*>(box->GetId(), boxDisplay));
            }
        }
    }

    this->gridService->AttachBoxesPoppedObserver(this);
    this->gridService->AttachNewColumnAddedObserver(this);
    this->gridService->AttachGameOverObserver(this);
}

presentation::GridUiDisplay::~GridUiDisplay() {
    this->gridService->DettachBoxesPoppedObserver(this);
    this->gridService->DettachNewColumnAddedObserver(this);
    this->gridService->DettachGameOverObserver(this);
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

        this->AddBoxDisappearAnimation(boxMapIt->second);
        delete boxMapIt->second;
        this->boxesById.erase(boxMapIt);
    }
}

void presentation::GridUiDisplay::OnNewColumnAdded() {
    data::IBox* box;
    BoxUiDisplay* boxDisplay;
    int column = data::Balancing::COLUMN_COUNT - 1;
    int row = 0;

    for (; row < data::Balancing::ROW_COUNT; row++) {
        box = this->gridDataReader->GetBoxAt(column, row);
        if (box != NULL) {
            boxDisplay = new BoxUiDisplay(box, this->gridService, this->gridXCoord, this->gridYCoord,
                this->boxDimention, 0.0f, this->newBoxYOffset);
            AddGameObject(boxDisplay);
            this->boxesById.insert(std::pair<int, BoxUiDisplay*>(box->GetId(), boxDisplay));
        }
    }
}

void presentation::GridUiDisplay::OnGameOver() {
    std::vector<game_engine::GameObject*>::iterator goIt;
    std::map<int, BoxUiDisplay*>::iterator boxMapIt = this->boxesById.begin();

    for (; boxMapIt != this->boxesById.end(); ++boxMapIt) {
        goIt = std::find(this->gameObjects.begin(), this->gameObjects.end(), boxMapIt->second);

        if (goIt != this->gameObjects.end()) {
            this->gameObjects.erase(goIt);
        }

        this->AddBoxDisappearAnimation(boxMapIt->second);
        delete boxMapIt->second;
    }

    this->boxesById.clear();
}

void presentation::GridUiDisplay::AddBoxDisappearAnimation(BoxUiDisplay* boxDisplay) {
    // Hacky way to keep the disappearing box on top of the others
    game_engine::Rectangle* rectangle = new game_engine::Rectangle(boxDisplay->GetX(), boxDisplay->GetY(),
        boxDisplay->GetWidth(), boxDisplay->GetHeight(), boxDisplay->GetColor());
    rectangle->SetAnimation(new BoxDisappearAnimation(rectangle, 0.5f, [this, rectangle] {
        this->RemoveGameObjectAfterUpdate(rectangle);
        }));
    AddGameObject(rectangle);
}

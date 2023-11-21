#include "GridService.h"
#include "../Data/Balancing.h"
#include <functional>

namespace services = ::ores::services;

services::GridService::GridService(data::GridModel* gridModel) {
    this->gridModel = gridModel;
}

void services::GridService::StartGame() {
    int column = 0;
    int row = 0;

    for (; column < this->gridModel->boxes.size(); column++) {
        for (row = 0; row < this->gridModel->boxes.size(); row++) {
            delete this->gridModel->boxes[column][row];
            if (column < 5) {
                this->gridModel->boxes[column][row] = NULL;
            }
            else {
                this->gridModel->boxes[column][row] =
                    new data::Box(++this->lastBoxId, rand() % data::Balancing::COLOR_COUNT, column, row);
            }
        }
    }
}

void services::GridService::TryPopBoxAt(int column, int row) {
    std::vector<std::pair<int, int>> boxesVisited;
    std::vector<std::pair<int, int>> boxesToPop;
    std::vector<int> poppedIds;
    int i = 0;
    int color;
    auto testBox{ [this, &color, &boxesToPop, &boxesVisited](int column, int row) {
            if (column < 0 || column >= data::Balancing::COLUMN_COUNT || row < 0 || row >= data::Balancing::ROW_COUNT)
                return;

            if (std::find(boxesVisited.begin(), boxesVisited.end(), std::pair<int, int>(column, row)) != boxesVisited.end()) return;

            boxesVisited.push_back(std::pair<int, int>(column, row));

            if (this->gridModel->boxes[column][row] != NULL
                && this->gridModel->boxes[column][row]->GetColor() == color) {
                boxesToPop.push_back(std::pair<int, int>(column, row));
            }
        }
    };

    if (column < 0 || column >= data::Balancing::COLUMN_COUNT || row < 0 || row >= data::Balancing::ROW_COUNT) return;
    if (this->gridModel->boxes[column][row] == NULL) return;

    color = this->gridModel->boxes[column][row]->GetColor();
    boxesToPop.push_back(std::pair<int, int>(column, row));
    boxesVisited.push_back(boxesToPop[0]);

    for (; i < boxesToPop.size(); ++i) {
        testBox(boxesToPop[i].first - 1, boxesToPop[i].second);
        testBox(boxesToPop[i].first + 1, boxesToPop[i].second);
        testBox(boxesToPop[i].first, boxesToPop[i].second - 1);
        testBox(boxesToPop[i].first, boxesToPop[i].second + 1);
    }

    if (boxesToPop.size() <= 1) return;

    for (i = 0; i < boxesToPop.size(); ++i) {
        poppedIds.push_back(this->gridModel->boxes[boxesToPop[i].first][boxesToPop[i].second]->GetId());
        delete this->gridModel->boxes[boxesToPop[i].first][boxesToPop[i].second];
        this->gridModel->boxes[boxesToPop[i].first][boxesToPop[i].second] = NULL;
    }

    for (i = 0; i < this->boxesPoppedObservers.size(); ++i) {
        this->boxesPoppedObservers[i]->OnBoxesPopped(poppedIds);
    }
}

void services::GridService::AttachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer) {
    this->boxesPoppedObservers.push_back(observer);
}

void services::GridService::DettachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer) {
    std::vector<observers::IBoxesPoppedObserver*>::iterator it
        = std::find(this->boxesPoppedObservers.begin(), this->boxesPoppedObservers.end(), observer);

    if (it != this->boxesPoppedObservers.end()) {
        this->boxesPoppedObservers.erase(it);
    }
}

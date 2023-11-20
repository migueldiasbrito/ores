#include "GridService.h"
#include "../Data/Balancing.h"

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
                this->gridModel->boxes[column][row] = new data::Box(rand() % data::Balancing::COLOR_COUNT);
            }
        }
    }
}

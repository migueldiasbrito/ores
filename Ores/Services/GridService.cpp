#include "GridService.h"

namespace services = ::ores::services;

services::GridService::GridService(data::GridModel* gridModel) {
    this->gridModel = gridModel;
}

void services::GridService::StartGame() {
    // change to [column][row]
    int i = 0;
    int j = 0;

    for (; i < this->gridModel->boxes.size(); i++) {
        for (j = 0; j < this->gridModel->boxes.size(); j++) {
            delete this->gridModel->boxes[i][j];
            if (j < 5) {
                this->gridModel->boxes[i][j] = NULL;
            }
            else {
                this->gridModel->boxes[i][j] = new data::Box(rand() % 5);
            }
        }
    }
}

#include "GridService.h"
#include "../Data/Balancing.h"
#include <map>
#include <queue>
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
    std::vector<std::pair<int, int>> visited;
    std::vector<std::pair<int, int>> pop;
    int i = 0;
    int color;
    auto testBox{ [this, &color, &pop, &visited](int column, int row) {
            if (column < 0 || column >= data::Balancing::COLUMN_COUNT || row < 0 || row >= data::Balancing::ROW_COUNT)
                return;

            if (std::find(visited.begin(), visited.end(), std::pair<int, int>(column, row)) != visited.end()) return;

            visited.push_back(std::pair<int, int>(column, row));

            if (this->gridModel->boxes[column][row] != NULL
                && this->gridModel->boxes[column][row]->GetColor() == color) {
                pop.push_back(std::pair<int, int>(column, row));
            }
        }
    };

    if (column < 0 || column >= data::Balancing::COLUMN_COUNT || row < 0 || row >= data::Balancing::ROW_COUNT) return;
    if (this->gridModel->boxes[column][row] == NULL) return;

    color = this->gridModel->boxes[column][row]->GetColor();
    pop.push_back(std::pair<int, int>(column, row));
    visited.push_back(pop[0]);

    for (; i < pop.size(); ++i) {
        testBox(pop[i].first - 1, pop[i].second);
        testBox(pop[i].first + 1, pop[i].second);
        testBox(pop[i].first, pop[i].second - 1);
        testBox(pop[i].first, pop[i].second + 1);
    }

    if (pop.size() <= 1) return;

    for (i = 0; i < pop.size(); ++i) {
        delete this->gridModel->boxes[pop[i].first][pop[i].second];
        this->gridModel->boxes[pop[i].first][pop[i].second] = NULL;
    }
}

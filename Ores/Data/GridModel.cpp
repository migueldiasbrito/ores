#include "GridModel.h"

namespace data = ::ores::data;

data::GridModel::GridModel() {
    // change to [column][row]
    int i = 0;
    int j = 0;
    std::vector<Box*>* row;

    for (; i < 10; i++) {
        row = new std::vector<Box*>();
        for (j = 0; j < 10; j++) {
            row->push_back(NULL);
        }
        this->boxes.push_back(*row);
    }
}

data::GridModel::~GridModel() {
    // change to [column][row]
    int i = 0;
    int j = 0;

    for (; i < this->boxes.size(); i++) {
        for (j = 0; j < this->boxes[i].size(); j++) {
            delete this->boxes[i][j];
            this->boxes[i][j] = NULL;
        }
    }
}

std::vector<std::vector<data::Box*>> data::GridModel::GetBoxes() {
    return this->boxes;
}

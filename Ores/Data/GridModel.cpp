#include "GridModel.h"
#include "Balancing.h"

namespace data = ::ores::data;

data::GridModel::GridModel() {
    int column = 0;
    int row = 0;
    std::vector<Box*>* newRow;

    for (; column < data::Balancing::COLUMN_COUNT; ++column) {
        newRow = new std::vector<Box*>();
        for (row = 0; row < data::Balancing::ROW_COUNT; ++row) {
            newRow->push_back(NULL);
        }
        this->boxes.push_back(*newRow);
    }
}

data::GridModel::~GridModel() {
    int column = 0;
    int row = 0;

    for (; column < this->boxes.size(); ++column) {
        for (row = 0; row < this->boxes[column].size(); ++row) {
            delete this->boxes[column][row];
            this->boxes[column][row] = NULL;
        }
    }
}

data::Box* data::GridModel::GetBoxAt(int column, int row) {
    return this->boxes[column][row];
}

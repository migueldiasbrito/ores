#include "Box.h"

namespace data = ::ores::data;

data::Box::Box(int id, int color, int column, int row) : id(id), color(color), column(column), row(row) {}

int data::Box::GetId() {
    return this->id;
}

int data::Box::GetColor() {
    return color;
}

int data::Box::GetColumn() {
    return this->column;
}

int data::Box::GetRow() {
    return this->row;
}

void data::Box::UpdateGridPosition(int column, int row) {
    int i = 0;

    this->column = column;
    this->row = row;

    for (; i < this->boxPositionUpdatedObservers.size(); ++i) {
        this->boxPositionUpdatedObservers[i]->OnBoxPositionUpdated(this->column, this->row);
    }
}

void data::Box::AttachBoxPositionUpdatedObserver(observers::IBoxPositionUpdatedObserver* observer) {
    this->boxPositionUpdatedObservers.push_back(observer);
}

void data::Box::DettachBoxPositionUpdatedObserver(observers::IBoxPositionUpdatedObserver* observer) {
    std::vector<observers::IBoxPositionUpdatedObserver*>::iterator it
        = std::find(this->boxPositionUpdatedObservers.begin(), this->boxPositionUpdatedObservers.end(), observer);

    if (it != this->boxPositionUpdatedObservers.end()) {
        this->boxPositionUpdatedObservers.erase(it);
    }
}

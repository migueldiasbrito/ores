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

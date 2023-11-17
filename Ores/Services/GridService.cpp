#include "GridService.h"

namespace services = ::ores::services;
namespace data = ::ores::data;

services::GridService::GridService(data::GridModel* gridModel) {
    this->gridModel = gridModel;
}

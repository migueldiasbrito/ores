#ifndef ORES_DATA_GRIDMODEL_H_
#define ORES_DATA_GRIDMODEL_H_

#include "IGridDataReader.h"

namespace ores {
    namespace data {
        class GridModel :
            public IGridDataReader
        {
        public:
            GridModel();
            ~GridModel();
            std::vector<std::vector<Box*>> GetBoxes();
            std::vector<std::vector<Box*>> boxes;
        };
    }
}

#endif // ORES_DATA_GRIDMODEL_H_

#ifndef ORES_DATA_GRIDMODEL_H_
#define ORES_DATA_GRIDMODEL_H_

#include "Box.h"
#include "IGridDataReader.h"

namespace ores {
    namespace data {
        class GridModel :
            public IGridDataReader
        {
        public:
            //! Contructor
            GridModel();

            //! Deletes all boxes
            ~GridModel();

            //! The grid boxes
            std::vector<std::vector<Box*>> boxes;

            IBox* GetBoxAt(int column, int row);
        };
    }
}

#endif // ORES_DATA_GRIDMODEL_H_

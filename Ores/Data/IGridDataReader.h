#ifndef ORES_DATA_IGRIDDATAREADER_H_
#define ORES_DATA_IGRIDDATAREADER_H_

#include "IDataReader.h"
#include "Box.h"
#include <vector>

namespace ores {
    namespace data {
        class IGridDataReader : IDataReader {
        public:
            // change to return a pointer
            virtual std::vector<std::vector<Box*>> GetBoxes() = 0;
        };
    }
}

#endif // ORES_DATA_IGRIDDATAREADER_H_

#ifndef ORES_DATA_IGRIDDATAREADER_H_
#define ORES_DATA_IGRIDDATAREADER_H_

#include "IDataReader.h"
#include "Box.h"
#include <vector>

namespace ores {
    namespace data {
        class IGridDataReader : IDataReader {
        public:
            //! Gets the Box at the specified column and row
            /*!
            \param column grid column
            \param row grid row
            \return the Box at the column and row
            */
            virtual Box* GetBoxAt(int column, int row) = 0;;
        };
    }
}

#endif // ORES_DATA_IGRIDDATAREADER_H_

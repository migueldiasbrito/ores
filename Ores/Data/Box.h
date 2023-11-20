#ifndef ORES_DATA_BOX_H_
#define ORES_DATA_BOX_H_

#include "IBox.h"

namespace ores {
    namespace data {
        class Box : IBox
        {
        public:
            //! Constructor
            /*!
            \param color an integer representing a color
            */
            Box(int id, int color, int column, int row);

            int GetId();
            int GetColor();
            int GetColumn();
            int GetRow();

            //! Current column
            int column = 0;

            //! Current row
            int row = 0;

        private:
            //! Unique Id
            const int id = 0;

            //! The color identifier
            const int color = 0;
        };
    }
}

#endif // ORES_DATA_BOX_H_

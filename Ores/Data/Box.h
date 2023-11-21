#ifndef ORES_DATA_BOX_H_
#define ORES_DATA_BOX_H_

#include "IBox.h"
#include <vector>

namespace ores {
    namespace data {
        class Box : IBox
        {
        public:
            //! Constructor
            /*!
            \param id a unique identifier
            \param color an integer representing a color
            \param column grid column
            \param row grid row
            */
            Box(int id, int color, int column, int row);

            //! Constructor
            /*!
            \param column new grid column
            \param row new grid row
            */
            void UpdateGridPosition(int column, int row);

            int GetId();
            int GetColor();
            int GetColumn();
            int GetRow();
            void AttachBoxPositionUpdatedObserver(observers::IBoxPositionUpdatedObserver* observer);
            void DettachBoxPositionUpdatedObserver(observers::IBoxPositionUpdatedObserver* observer);
        private:
            //! Unique Id
            const int id = 0;

            //! The color identifier
            const int color = 0;

            //! Current column
            int column = 0;

            //! Current row
            int row = 0;

            //! Boxes popped observers
            std::vector<observers::IBoxPositionUpdatedObserver*> boxPositionUpdatedObservers;
        };
    }
}

#endif // ORES_DATA_BOX_H_

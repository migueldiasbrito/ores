#ifndef ORES_PRESENTATION_BOXUIDISPLAY_H_
#define ORES_PRESENTATION_BOXUIDISPLAY_H_

#include "../Data/IBox.h"
#include "../GameEngine/Rectangle.h"
#include "../Observers/IBoxPositionUpdatedObserver.h"
#include "../Services/IGridService.h"

namespace ores {
    namespace presentation {
        class BoxUiDisplay : public game_engine::Rectangle, observers::IBoxPositionUpdatedObserver {
        public:
            //! Constructor
            /*!
            \param box the box to be displayed
            \param box width and height
            */
            BoxUiDisplay(data::IBox* box, services::IGridService* gridService, float xCoordOnZero, float yCoordOnZero,
                float boxDimention);

            void OnClick(int x, int y);
            void OnBoxPositionUpdated(int column, int row);
        private:
            //! Box represented
            data::IBox* box;

            //! The grid service
            services::IGridService* gridService;

            //! x coordinate for boxdisplay on (0,0) in the grid
            float xCoordOnZero;

            //! y coordinate for boxdisplay on (0,0) in the grid
            float yCoordOnZero;
        };
    }
}

#endif // ORES_PRESENTATION_BOXUIDISPLAY_H_

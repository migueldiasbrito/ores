#ifndef ORES_PRESENTATION_BOXUIDISPLAY_H_
#define ORES_PRESENTATION_BOXUIDISPLAY_H_

#include "../Data/IBox.h"
#include "../GameEngine/Rectangle.h"
#include "../Services/IGridService.h"

namespace ores {
    namespace presentation {
        class BoxUiDisplay : public game_engine::Rectangle {
        public:
            //! Constructor
            /*!
            \param box the box to be displayed
            */
            BoxUiDisplay(data::IBox* box, services::IGridService* gridService);

            void OnClick(int x, int y);
        private:
            //! Box represented
            data::IBox* box;

            //! The grid service
            services::IGridService* gridService;
        };
    }
}

#endif // ORES_PRESENTATION_BOXUIDISPLAY_H_

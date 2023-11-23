#ifndef ORES_PRESENTATION_GRIDUIDISPLAY_H_
#define ORES_PRESENTATION_GRIDUIDISPLAY_H_

#include "../Data/IGridDataReader.h"
#include "../GameEngine/CompositeGameObject.h"
#include "../Observers/IBoxesPoppedObserver.h"
#include "../Observers/INewColumnAddedObserver.h"
#include "../Observers/IGameOverObserver.h"
#include "../Services/IGridService.h"
#include "BoxUiDisplay.h"
#include <map>

namespace ores {
    namespace presentation {
        class GridUiDisplay : public game_engine::CompositeGameObject, observers::IBoxesPoppedObserver,
            observers::INewColumnAddedObserver, observers::IGameOverObserver {
        public:
            //! Constructor
            /*!
            \param engine Game engine where context is drawn
            \param fontCache FontCache to load fonts
            \param width window width
            \param height window height
            */
            GridUiDisplay(data::IGridDataReader* gridDataReader, services::IGridService* gridService, float width,
                float height);

            //! Detaches observer from service
            virtual ~GridUiDisplay() override;

            void OnBoxesPopped(std::vector<int> boxesPoppedIds);
            void OnNewColumnAdded();
            void OnGameOver();
        private:
            //! All Box Display by id
            std::map<int, BoxUiDisplay*> boxesById;

            //! the grid data reader
            data::IGridDataReader* gridDataReader = NULL;

            //! the grid service
            services::IGridService* gridService = NULL;

            //! individual box width and height
            float boxDimention = 0.0f;

            //! x coordinate for boxdisplay on (0,0) in the grid
            float gridXCoord = 0.0f;

            //! y coordinate for boxdisplay on (0,0) in the grid
            float gridYCoord = 0.0f;

            //! Y offset for new boxes when new column appears
            float newBoxYOffset = 0.0f;

            //! Creates a Rectangle with BoxDisappearingAnimation
            /*!
            \param boxDisplay the box to be deleted
            */
            void AddBoxDisappearAnimation(BoxUiDisplay* boxDisplay);
        };
        
    }
}

#endif // ORES_PRESENTATION_GRIDUIDISPLAY_H_

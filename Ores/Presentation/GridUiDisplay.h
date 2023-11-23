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
            */
            GridUiDisplay(data::IGridDataReader* gridDataReader, services::IGridService* gridService);

            //! Detaches observer from service
            virtual ~GridUiDisplay();

            void OnBoxesPopped(std::vector<int> boxesPoppedIds);
            void OnNewColumnAdded();
            void OnGameOver();
        private:
            //! All Box Display by id
            std::map<int, BoxUiDisplay*> boxesById;

            //! the grid data reader
            data::IGridDataReader* gridDataReader;

            //! the grid service
            services::IGridService* gridService;
        };
        
    }
}

#endif // ORES_PRESENTATION_GRIDUIDISPLAY_H_

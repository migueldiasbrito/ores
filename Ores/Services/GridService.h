#ifndef ORES_SERVICE_GRIDSERVICE_H_
#define ORES_SERVICE_GRIDSERVICE_H_

#include "IGridService.h"
#include "../Data/GridModel.h"

namespace ores {
    namespace services {
        class GridService : public IGridService {
        public:
            //! Constructor
            /*!
            \param gridModel GridModel in which this service acts
            */
            GridService(data::GridModel* gridModel);

            void StartGame();
            void TryPopBoxAt(int column, int row);
            void AttachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer);
            void DettachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer);
        private:
            //! GridModel in which this service acts
            data::GridModel* gridModel;

            //! Last created box unique Id
            int lastBoxId = -1;

            //! Boxes popped observers
            std::vector<observers::IBoxesPoppedObserver*> boxesPoppedObservers;

            //! Updates boxes position in the grid after a deletion
            void UpdateBoxesPosition();
        };
    }
}

#endif // ORES_SERVICE_GRIDSERVICE_H_

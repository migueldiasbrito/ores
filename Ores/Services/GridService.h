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
            void InsertNewColumn();
            void AttachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer);
            void DettachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer);
            void AttachNewColumnAddedObserver(observers::INewColumnAddedObserver* observer);
            void DettachNewColumnAddedObserver(observers::INewColumnAddedObserver* observer);
            void AttachGameOverObserver(observers::IGameOverObserver* observer);
            void DettachGameOverObserver(observers::IGameOverObserver* observer);
        private:
            //! GridModel in which this service acts
            data::GridModel* gridModel;

            //! Last created box unique Id
            int lastBoxId = -1;

            //! Boxes popped observers
            std::vector<observers::IBoxesPoppedObserver*> boxesPoppedObservers;

            //! New column added observers
            std::vector<observers::INewColumnAddedObserver*> newColumnAddedObservers;

            //! Game over observers
            std::vector<observers::IGameOverObserver*> gameOverObservers;

            //! Updates boxes position in the grid after a deletion
            void UpdateBoxesPosition();
        };
    }
}

#endif // ORES_SERVICE_GRIDSERVICE_H_

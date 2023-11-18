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
        private:
            //! GridModel in which this service acts
            data::GridModel* gridModel;
        };
    }
}

#endif // ORES_SERVICE_GRIDSERVICE_H_

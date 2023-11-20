#ifndef ORES_SERVICE_IGRIDSERVICE_H_
#define ORES_SERVICE_IGRIDSERVICE_H_

#include "IService.h"

namespace ores {
    namespace services {
        class IGridService : IService {
        public:
            //! Creates a new Grid of random colored Box
            virtual void StartGame() = 0;

            //! Tries to destroys Box at given column and row and adjacent ones with the same color
            /*!
            \param column column position of the box
            \param row grid row position of the box
            */
            virtual void TryPopBoxAt(int column, int row) = 0;
        };
    }
}

#endif // ORES_SERVICE_IGRIDSERVICE_H_

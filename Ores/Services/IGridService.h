#ifndef ORES_SERVICE_IGRIDSERVICE_H_
#define ORES_SERVICE_IGRIDSERVICE_H_

#include "IService.h"

namespace ores {
    namespace services {
        class IGridService : IService {
        public:
            //! Creates a new Grid of random colored Box
            virtual void StartGame() = 0;
        };
    }
}

#endif // ORES_SERVICE_IGRIDSERVICE_H_

#ifndef ORES_SERVICE_IGRIDSERVICE_H_
#define ORES_SERVICE_IGRIDSERVICE_H_

#include "IService.h"

namespace ores {
    namespace services {
        class IGridService : IService {
        public:
            virtual void StartGame() = 0;
        };
    }
}

#endif // ORES_SERVICE_IGRIDSERVICE_H_

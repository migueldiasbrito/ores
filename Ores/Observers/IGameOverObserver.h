#ifndef ORES_OBSERVERS_IGAMEOVEROBSERVER_H_
#define ORES_OBSERVERS_IGAMEOVEROBSERVER_H_

#include <vector>

namespace ores {
    namespace observers {
        class IGameOverObserver
        {
        public:
            virtual void OnGameOver() = 0;
        };
    }
}

#endif // ORES_OBSERVERS_IGAMEOVEROBSERVER_H_

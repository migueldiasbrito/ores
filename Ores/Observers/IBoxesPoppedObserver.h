#ifndef ORES_OBSERVERS_IBOXPOPPEDOBSERVER_H_
#define ORES_OBSERVERS_IBOXPOPPEDOBSERVER_H_

#include <vector>

namespace ores {
    namespace observers {
        class IBoxesPoppedObserver
        {
        public:
            virtual void OnBoxesPopped(std::vector<int> boxesPoppedIds) = 0;
        };
    }
}

#endif // ORES_OBSERVERS_IBOXPOPPEDOBSERVER_H_

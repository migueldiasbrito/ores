#ifndef ORES_OBSERVERS_IBOXPOSITIONUPDATEDOBSERVER_H_
#define ORES_OBSERVERS_IBOXPOSITIONUPDATEDOBSERVER_H_

namespace ores {
    namespace observers {
        class IBoxPositionUpdatedObserver
        {
        public:
            virtual void OnBoxPositionUpdated(int column, int row) = 0;
        };
    }
}

#endif // ORES_OBSERVERS_IBOXPOSITIONUPDATEDOBSERVER_H_

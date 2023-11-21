#ifndef ORES_OBSERVERS_INEWCOLUMNADDEDOBSERVEROBSERVER_H_
#define ORES_OBSERVERS_INEWCOLUMNADDEDOBSERVEROBSERVER_H_

namespace ores {
    namespace observers {
        class INewColumnAddedObserver
        {
        public:
            virtual void OnNewColumnAdded() = 0;
        };
    }
}

#endif // ORES_OBSERVERS_INEWCOLUMNADDEDOBSERVEROBSERVER_H_

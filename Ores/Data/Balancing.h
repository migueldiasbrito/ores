#ifndef ORES_DATA_BALANCING_H_
#define ORES_DATA_BALANCING_H_

namespace ores {
    namespace data {
        static class Balancing {
        public:
            //! Total number of columns
            static const int COLUMN_COUNT = 10;

            //! Total number of rows
            static const int ROW_COUNT = 10;

            //! Total number of colors
            static const int COLOR_COUNT = 5;

            //! Time before new column appears
            static const int NEW_COLUMN_TIME = 7;
        };
    }
};

#endif // ORES_DATA_BALANCING_H_

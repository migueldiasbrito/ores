#ifndef ORES_DATA_BOX_H_
#define ORES_DATA_BOX_H_

namespace ores {
    namespace data {
        class Box
        {
        public:
            //! Constructor
            /*!
            \param color an integer representing a color
            */
            Box(int color);

            //! Gets the Box color code
            /*!
            \return the box color identifier
            */
            inline int GetColor() { return color; }
        private:
            //! The color identifier
            int color;
        };
    }
}

#endif // ORES_DATA_BOX_H_

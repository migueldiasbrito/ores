#ifndef ORES_DATA_IBOX_H_
#define ORES_DATA_IBOX_H_

namespace ores {
    namespace data {
        class IBox {
        public:
            //! Gets the Box unique Id
            /*!
            \return the box unique Id
            */
            virtual int GetId() = 0;

            //! Gets the Box color code
            /*!
            \return the box color identifier
            */
            virtual int GetColor() = 0;

            //! Gets the Box current column
            /*!
            \return the box current column
            */
            virtual int GetColumn() = 0;

            //! Gets the Box current row
            /*!
            \return the box current row
            */
            virtual int GetRow() = 0;
        };
    }
}

#endif // ORES_DATA_IBOX_H_

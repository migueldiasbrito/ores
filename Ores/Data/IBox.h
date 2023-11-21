#ifndef ORES_DATA_IBOX_H_
#define ORES_DATA_IBOX_H_

#include "../Observers/IBoxPositionUpdatedObserver.h"

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

            //! Adds an observer for when box position is updated
            /*!
            \param observer the observer to attach
            */
            virtual void AttachBoxPositionUpdatedObserver(observers::IBoxPositionUpdatedObserver* observer) = 0;

            //! Removes an observer for when box position is updated
            /*!
            \param observer the observer to dettach
            */
            virtual void DettachBoxPositionUpdatedObserver(observers::IBoxPositionUpdatedObserver* observer) = 0;
        };
    }
}

#endif // ORES_DATA_IBOX_H_

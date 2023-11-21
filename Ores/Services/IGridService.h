#ifndef ORES_SERVICE_IGRIDSERVICE_H_
#define ORES_SERVICE_IGRIDSERVICE_H_

#include "IService.h"
#include "../Observers/IBoxesPoppedObserver.h"
#include "../Observers/INewColumnAddedObserver.h"

namespace ores {
    namespace services {
        class IGridService : IService {
        public:
            //! Creates a new Grid of random colored Box
            virtual void StartGame() = 0;

            //! Tries to destroys Box at given column and row and adjacent ones with the same color
            /*!
            \param column column position of the box
            \param row grid row position of the box
            */
            virtual void TryPopBoxAt(int column, int row) = 0;

            //! Adds a new column to the right pushing existing ones to the left
            virtual void InsertNewColumn() = 0;

            //! Adds an observer for when box is popped
            /*!
            \param observer the observer to attach
            */
            virtual void AttachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer) = 0;

            //! Removes an observer for when box is popped
            /*!
            \param observer the observer to dettach
            */
            virtual void DettachBoxesPoppedObserver(observers::IBoxesPoppedObserver* observer) = 0;

            //! Adds an observer for when a new column is added
            /*!
            \param observer the observer to attach
            */
            virtual void AttachNewColumnAddedObserver(observers::INewColumnAddedObserver* observer) = 0;

            //! Removes an observer for when a new column is added
            /*!
            \param observer the observer to dettach
            */
            virtual void DettachNewColumnAddedObserver(observers::INewColumnAddedObserver* observer) = 0;
        };
    }
}

#endif // ORES_SERVICE_IGRIDSERVICE_H_

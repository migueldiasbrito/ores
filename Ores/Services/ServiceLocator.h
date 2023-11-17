#ifndef ORES_SERVICE_SERVICELOCATOR_H_
#define ORES_SERVICE_SERVICELOCATOR_H_

#include <map>
#include <typeindex>
#include "IService.h"

namespace ores {
    namespace services {
        class ServiceLocator {
        public:
            //! Adds a Service
            /*!
            \param service the service to be added
            */
            template <class TService>
            static void AddService(TService* service) {
                static_assert(std::is_base_of<IService, TService>::value, "TService must derive from IService");

                services.insert(std::pair<std::type_index, IService*>(typeid(TService), (IService*)service));
            }

            //! Gets a Service
            /*!
            \return the service of the specified type or NULL if it doesn't exist
            */
            template <class TService>
            static TService* GetService() {
                static_assert(std::is_base_of<IService, TService>::value, "TService must derive from IService");

                std::map<std::type_index, IService*>::iterator it = services.find(typeid(TService));

                if (it != services.end()) {
                    return (TService*)it->second;
                }

                return NULL;
            }
        private:
            //! Services by type
            static std::map<std::type_index, IService*> services;
        };
    }
}

#endif // ORES_SERVICE_SERVICELOCATOR_H_

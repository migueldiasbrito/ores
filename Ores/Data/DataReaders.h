#ifndef ORES_DATA_DATAREADERS_H_
#define ORES_DATA_DATAREADERS_H_

#include <map>
#include <typeindex>
#include "IDataReader.h"

namespace ores {
    namespace data {
        class DataReaders {
        public:
            //! Adds a Data Reader
            /*!
            \param dataReader the data reader to be added
            */
            template <class TDataReader>
            static void AddDataReader(TDataReader* dataReader) {
                static_assert(std::is_base_of<IDataReader, TDataReader>::value, "TDataReader must derive from IDataReader");

                dataReaders.insert(std::pair<std::type_index, IDataReader*>(typeid(TDataReader), (IDataReader*) dataReader));
            }

            //! Gets a Data Reader
            /*!
            \return the data reader of the specified type or NULL if it doesn't exist
            */
            template <class TDataReader>
            static TDataReader* GetDataReader() {
                static_assert(std::is_base_of<IDataReader, TDataReader>::value, "TDataReader must derive from IDataReader");

                std::map<std::type_index, IDataReader*>::iterator it = dataReaders.find(typeid(TDataReader));

                if (it != dataReaders.end()) {
                    return (TDataReader*) it->second;
                }

                return NULL;
            }
        private:
            //! Data readers by type
            static std::map<std::type_index, IDataReader*> dataReaders;
        };
    }
}

#endif // ORES_DATA_DATAREADERS_H_

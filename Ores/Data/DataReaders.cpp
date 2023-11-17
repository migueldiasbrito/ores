#include "DataReaders.h"

namespace data = ::ores::data;

std::map<std::type_index, data::IDataReader*> data::DataReaders::dataReaders;

#include "ServiceLocator.h"

namespace services = ::ores::services;

std::map<std::type_index, services::IService*> services::ServiceLocator::services;

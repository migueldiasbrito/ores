#include "Config.h"

namespace presentation = ::ores::presentation;
namespace engine = ::ores::game_engine;

const engine::Color presentation::Config::colors[] = {
    engine::Color(0xFF, 0x00, 0x00),
    engine::Color(0x00, 0xFF, 0x00),
    engine::Color(0x00, 0x00, 0xFF),
    engine::Color(0xFF, 0xFF, 0x00),
    engine::Color(0xFF, 0x00, 0xFF),
};

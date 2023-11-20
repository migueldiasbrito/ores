#include "Color.h"

namespace engine = ::ores::game_engine;

engine::Color::Color() {}

engine::Color::Color(int red, int green, int blue) : red(red), green(green), blue (blue) {}

engine::Color::Color(int red, int green, int blue, int alpha) : red(red), green(green), blue(blue), alpha(alpha) {}

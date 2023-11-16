#include "Rectangle.h"
#include <SDL_rect.h>
#include <SDL.h>

namespace engine = ::ores::game_engine;

engine::Rectangle::Rectangle(float x, float y, float width, float height, int red, int green, int blue, int alpha)
    : x(x), y(y), width(width), height(height), red(red), green(green), blue(blue), alpha(alpha) {}

void engine::Rectangle::Draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, width, height };

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);

    SDL_RenderFillRect(renderer, &rect);
}

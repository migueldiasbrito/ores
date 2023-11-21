#include "Rectangle.h"
#include <SDL_rect.h>
#include <SDL.h>

namespace engine = ::ores::game_engine;

engine::Rectangle::Rectangle(float x, float y, float width, float height, Color color)
    : x(x), y(y), width(width), height(height), color(color) {}

void engine::Rectangle::Draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, width, height };

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);

    SDL_RenderFillRect(renderer, &rect);
}

void engine::Rectangle::SetWidth(float width) {
    this->width = width;
}

void engine::Rectangle::SetHeight(float height) {
    this->height = height;
}

#include "Rectangle.h"
#include <SDL_rect.h>
#include <SDL.h>

namespace engine = ::ores::game_engine;

engine::Rectangle::Rectangle(float x, float y, float width, float height, int red, int green, int blue, int alpha)
	: x(x), y(y), width(width), height(height),	red(red), green(green), blue(blue), alpha(alpha) {}

void engine::Rectangle::Draw(SDL_Renderer* gRenderer) {
	SDL_Rect rect = { x, y, width, height };

	SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(gRenderer, red, green, blue, alpha);

	SDL_RenderFillRect(gRenderer, &rect);
}

void engine::Rectangle::Update(float elapsedTime) {}

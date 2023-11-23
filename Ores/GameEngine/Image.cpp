#include "Image.h"

namespace engine = ::ores::game_engine;

engine::Image::~Image() {
    SDL_DestroyTexture(this->texture);
    this->texture = NULL;
}

void engine::Image::Draw(SDL_Renderer* renderer) {
    SDL_Rect renderQuad = { this->x, this->y, this->width, this->height };
    SDL_RenderCopy(renderer, this->texture, NULL, &renderQuad);
}

#include "Text.h"
#include <iostream>

namespace engine = ::ores::game_engine;

engine::Text::Text(SDL_Renderer* renderer, FontCache& fontCache, std::string fontFilename, int fontSize,
    std::string text, float x, float y, Color color) {

    SDL_Surface* surface;
    SDL_Color sdlColor = color.ToSdlColor();
    TTF_Font* font = fontCache.LoadFont(fontFilename, fontSize);

    if (font != NULL) {
        surface = TTF_RenderText_Solid(font, text.c_str(), sdlColor);
        if (surface == NULL) {
            std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        }
        else {
            this->texture = SDL_CreateTextureFromSurface(renderer, surface);

            if (this->texture == NULL) {
                std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
            }
            else {
                this->width = surface->w;
                this->height = surface->h;
            }

            SDL_FreeSurface(surface);
        }
    }

    this->x = x;
    this->y = y;
}

void engine::Text::CenterAt(float x, float y, float width, float height) {
    this->x = x + width / 2.0f - this->width / 2.0f;
    this->y = y + height / 2.0f - this->height / 2.0f;
}

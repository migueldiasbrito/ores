#include "Text.h"
#include <iostream>

namespace engine = ::ores::game_engine;

engine::Text::Text(SDL_Renderer* renderer, FontCache& fontCache, std::string fontFilename, int fontSize,
    std::string text, float x, float y, int red, int green, int blue, int alpha) {

    SDL_Surface* surface;
    SDL_Color color = { red, green, blue, alpha };
    TTF_Font* font = fontCache.LoadFont(fontFilename, fontSize);

    if (font != NULL) {
        surface = TTF_RenderText_Solid(font, text.c_str(), color);
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

#include "Button.h"
#include "Rectangle.h"
#include "Text.h"

namespace engine = ::ores::game_engine;

engine::Button::Button(SDL_Renderer* renderer, FontCache& fontCache, float x, float y, float width, float height,
    int bgRed, int bgGreen, int bgBlue, int bgAlpha, std::string fontFilename, int fontSize, std::string text,
    int textRed, int textGreen, int textBlue, int textAlpha) {

    this->gameObjects.push_back(new Rectangle(x, y, width, height, bgRed, bgGreen, bgBlue, bgAlpha));

    Text* buttonText = new Text(renderer, fontCache, fontFilename, fontSize, text, 0, 0, textRed, textGreen, textBlue, textAlpha);
    buttonText->CenterAt(x, y, width, height);
    this->gameObjects.push_back(buttonText);

}
#include "Button.h"
#include "Text.h"

namespace engine = ::ores::game_engine;

engine::Button::Button(SDL_Renderer* renderer, FontCache& fontCache, float x, float y, float width, float height,
    Color backgroundColor, std::string fontFilename, int fontSize, std::string text, Color textColor,
    std::function<void()> callback) : callback(callback) {

    this->gameObjects.push_back(new Rectangle(x, y, width, height, backgroundColor));

    Text* buttonText = new Text(renderer, fontCache, fontFilename, fontSize, text, 0, 0, textColor);
    buttonText->CenterAt(x, y, width, height);
    this->gameObjects.push_back(buttonText);

}

void engine::Button::OnClick(int x, int y) {
    if (x >= this->GetRectangle()->GetLeft() && x <= this->GetRectangle()->GetRight()
        && y >= this->GetRectangle()->GetTop() && y <= this->GetRectangle()->GetBottom()) {
        this->callback();
    }
}

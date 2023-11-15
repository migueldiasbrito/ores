#include "FontCache.h"
#include <iostream>

namespace engine = ::ores::game_engine;

TTF_Font* engine::FontCache::LoadFont(std::string filename, int size) {
	std::map<std::string, std::map<int, TTF_Font*>>::iterator nameIt = this->fontCache.find(filename);
	std::map<int, TTF_Font*>::iterator sizeIt;
	std::map<int, TTF_Font*>* sizeMap;
	TTF_Font* font;

	if (nameIt == this->fontCache.end()) {
		sizeMap = new std::map<int, TTF_Font*>();
		sizeIt = sizeMap->end();

		this->fontCache.insert(std::pair<std::string, std::map<int, TTF_Font*>>(filename, *sizeMap));
	}
	else {
		sizeMap = &nameIt->second;
		sizeIt = nameIt->second.find(size);
	}

	if (sizeIt == sizeMap->end()) {
		font = TTF_OpenFont(filename.c_str(), size);

		if (font == NULL) {
			std::cout << "Unable to load font " << filename.c_str() << "! SDL_ttf Error: " << TTF_GetError() << std::endl;
			return NULL;
		}
	}
	else {
		font = sizeIt->second;
	}

	return font;
}

void engine::FontCache::Close() {
	std::map<std::string, std::map<int, TTF_Font*>>::iterator nameIt = this->fontCache.begin();
	std::map<int, TTF_Font*>::iterator sizeIt;

	for (; nameIt != this->fontCache.end(); nameIt++) {
		sizeIt = nameIt->second.begin();

		for (; sizeIt != nameIt->second.end(); sizeIt++) {
			TTF_CloseFont(sizeIt->second);
			sizeIt->second = NULL;
		}
	}
}

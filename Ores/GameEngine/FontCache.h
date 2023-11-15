#ifndef ORES_GAMEENGINE_FONTCACHE_H_
#define ORES_GAMEENGINE_FONTCACHE_H_

#include <map>
#include <SDL_ttf.h>
#include <string>

namespace ores {
	namespace game_engine {
		class FontCache {
		public:
			//! Loads or retrieves font from file
			/*!
			\param filename font filename.
			\return loaded font in a SDL container
			*/
			TTF_Font* LoadFont(std::string filename, int size);

			//! Unloads all the fonts
			void Close();

		private:
			//! Cache.
			/*!
			For every font loaded, it is inserted in this map with its filename.
			*/
			std::map<std::string, std::map<int, TTF_Font*>> fontCache;
		};
	}
}

#endif  // ORES_GAMEENGINE_FONTCACHE_H_

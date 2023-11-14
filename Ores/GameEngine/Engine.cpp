#include "Engine.h"
#include <iostream>

namespace engine = ::ores::game_engine;

bool engine::Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	gWindow = SDL_CreateWindow("Ores", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);

	if (gWindow == NULL) {
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (gRenderer == NULL) {
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError()
			<< std::endl;
		return false;
	}

	// start image loader
	/*imgFlags = IMG_INIT_PNG;

	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "SDL_image could not initialize! SDL_image Error: "
			<< IMG_GetError() << std::endl;
		return false;
	}*/

	// start font loader
	/*if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: "
			<< TTF_GetError() << std::endl;
		return false;
	}*/
	/*
	// start audio loader
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << "SDL_mixer could not initialize! SDL_mixer Error : "
			<< Mix_GetError() << endl;
		return false;
	}*/

	return true;
}

void engine::Engine::AddGameObject(GameObject* gameObject) {
	gameObjects.push_back(gameObject);
}

void engine::Engine::Loop() {
	this->looping = true;

	while (this->looping) {
		this->HandleInput();
		// todo get elapsed time
		this->Update(1.0f / 60.0f);
		this->Draw();

		// todo wait until next frame
	}
}

void engine::Engine::Close() {
	//imageCache.Close();
	//fontCashe.close();
	//soundCashe.close();

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Mix_Quit();
	//TTF_Quit();
	//IMG_Quit();
	SDL_Quit();
}

void engine::Engine::Update(float elapsedTime) {
	int i;

	for (i = 0; i < gameObjects.size(); ++i) {
		if (gameObjects[i] != NULL) {
			gameObjects[i]->Update(elapsedTime);
		}
	}
}

void engine::Engine::Draw() {
	int i;

	SDL_SetRenderDrawColor(this->gRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(this->gRenderer);

	for (i = 0; i < gameObjects.size(); ++i) {
		if (gameObjects[i] != NULL) {
			gameObjects[i]->Draw(this->gRenderer);
		}
	}

	SDL_RenderPresent(this->gRenderer);
}

void engine::Engine::HandleInput() {
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			this->looping = false;
		}
	}
}

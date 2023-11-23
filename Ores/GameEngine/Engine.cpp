#include "Engine.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <SDL_ttf.h>

namespace engine = ::ores::game_engine;

bool engine::Engine::Init() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Ores", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (window == NULL) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
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
    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: "
            << TTF_GetError() << std::endl;
        return false;
    }

    // start audio loader
    /*if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error : "
            << Mix_GetError() << endl;
        return false;
    }*/

    return true;
}

void engine::Engine::LoadScene(GameObject* scene) {
    delete this->currentScene;

    this->currentScene = scene;
}

void engine::Engine::Loop() {
    std::chrono::system_clock::time_point currentFrameTimestamp;
    std::chrono::system_clock::time_point lastFrameTimestamp = std::chrono::system_clock::now();
    std::chrono::duration<float> secondsBetweenFrames{ 1.0f / 60.0f };
    std::chrono::duration<float> waitTime;
    float elapsedTime;

    this->looping = true;

    while (this->looping) {
        this->HandleInput();
        
        currentFrameTimestamp = std::chrono::system_clock::now();
        elapsedTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentFrameTimestamp - lastFrameTimestamp).count();

        this->Update(elapsedTime);
        this->Draw();

        lastFrameTimestamp = currentFrameTimestamp;
        waitTime = secondsBetweenFrames - (std::chrono::system_clock::now() - lastFrameTimestamp);

        if (waitTime.count() > 0) {
            std::this_thread::sleep_for(waitTime);
        }
    }
}

void engine::Engine::Close() {
    int i = 0;

    delete this->currentScene;
    this->currentScene = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    //Mix_Quit();
    TTF_Quit();
    //IMG_Quit();
    SDL_Quit();
}

void engine::Engine::GetResolution(int& width, int& height) {
    SDL_GetWindowSize(this->window, &width, &height);
}

void engine::Engine::Update(float elapsedTime) {
    int i;

    this->currentScene->Update(elapsedTime);
}

void engine::Engine::Draw() {
    int i;

    SDL_SetRenderDrawColor(this->renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(this->renderer);

    this->currentScene->Draw(this->renderer);

    SDL_RenderPresent(this->renderer);
}

void engine::Engine::HandleInput() {
    SDL_Event e;
    int i;

    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_MOUSEBUTTONUP) {
            int x, y;
            SDL_GetMouseState(&x, &y);

            this->currentScene->OnClick(x, y);
        }

        if (e.type == SDL_QUIT) {
            this->looping = false;
        }
    }
}

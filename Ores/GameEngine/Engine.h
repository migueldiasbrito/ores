#ifndef ORES_GAMEENGINE_ENGINE_H_
#define ORES_GAMEENGINE_ENGINE_H_

#include <SDL.h>
#include <vector>
#include "GameObject.h"

namespace ores {
    namespace game_engine {
        class Engine {
        public:
            //! Starts the graphics engine
            /*!
            \return true if the engine started
            */
            bool Init();

            //! Loads and changes the displayed scene
            /*!
            \param scene scene to be loaded
            */
            void LoadScene(GameObject* scene);

            //! Handles the engine loop
            void Loop();

            //! Terminates the engine
            void Close();

            //! Returns the renderer
            inline SDL_Renderer* GetRenderer() { return renderer; }

            //! Stops the loop after the current iteration
            inline void StopLoop() { this->looping = false; }
        private:
            //! SDL Window.
            /*!
            The window is created on init method and destroyed on close
            */
            SDL_Window* window = NULL;

            //! SDL Renderer.
            /*!
            The renderer is reponsible for all drawing operations. Like the SDL
            window, is created on init and destroyed on close
            */
            SDL_Renderer* renderer = NULL;

            //! Looping
            /*!
            Engine is looping
            */
            bool looping = false;

            //! Current scene displayed
            GameObject* currentScene;

            //! Updates all Game Objects
            void Update(float elapsedTime);

            //! Draws all Game Objects
            void Draw();

            //! Handles input
            void HandleInput();
        };
    }
}

#endif  // ORES_GAMEENGINE_ENGINE_H_

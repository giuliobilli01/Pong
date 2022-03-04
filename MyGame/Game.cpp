#include "Game.hpp"

Game::Game() {
	this->gameWindow = nullptr;
	this->isRunning = true;
}

bool Game::initializeGame() {
	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlInitResult != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	SDL_Window* gameWindow = SDL_CreateWindow("My Game", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (gameWindow == NULL) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	return true;
}

void Game::runGameLoop() {

	while (this->isRunning) {

		this->ProcessInput();
	}
}

void Game::shutDownGame() {
	SDL_DestroyWindow(this->gameWindow);
	SDL_Quit();
}

void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		
		case SDL_QUIT:
			this->isRunning = false;
			break;
		}
	}
	
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) isRunning = false;
}

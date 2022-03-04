#include "Game.hpp"

Game::Game() {
	this->gameWindow = nullptr;
	this->isRunning = true;
	this->gameRenderer = nullptr;
}

bool Game::initializeGame() {
	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlInitResult != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	this->gameWindow = SDL_CreateWindow("My Game", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (gameWindow == NULL) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	this->gameRenderer = SDL_CreateRenderer(this->gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gameRenderer == NULL) {
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return false;
	}
	return true;
}

void Game::runGameLoop() {

	while (this->isRunning) {

		this->processInput();
		//update
		this->generateOutput();
	}
}

void Game::shutDownGame() {
	SDL_DestroyWindow(this->gameWindow);
	SDL_DestroyRenderer(this->gameRenderer);
	SDL_Quit();
}

void Game::processInput() {
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

void Game::generateOutput() {
	SDL_SetRenderDrawColor(this->gameRenderer, 0, 0, 255, 255);

	// Clear the back buffer 
	SDL_RenderClear(this->gameRenderer);

	// Draw output

	// Switch to front buffer
	SDL_RenderPresent(this->gameRenderer);
}	

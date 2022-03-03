#include "Game.hpp"

Game::Game() {

}

bool Game::initializeGame() {
	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlInitResult != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	SDL_Window* gameWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (gameWindow == NULL) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}
	return true;
}

void Game::runGameLoop() {

}
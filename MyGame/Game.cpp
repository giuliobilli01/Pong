#include "Game.hpp"

Game::Game() {
	this->gameWindow = nullptr;
	this->isRunning = true;
	this->gameRenderer = nullptr;
	this->BallPos.x = WINDOW_WIDTH / 2;
	this->BallPos.y = WINDOW_HEIGHT / 2;
	this->PaddlePos.x = 1;
	this->PaddlePos.y = WINDOW_HEIGHT / 2;
	this->ticksCounter = 0;
	this->paddleDir = 0;
	
}

bool Game::initializeGame() {
	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlInitResult != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	this->gameWindow = SDL_CreateWindow("My Game", 30, 30, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
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
		this->updateGame();
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
	if (state[SDL_SCANCODE_W]) this->paddleDir -= 1;
	if (state[SDL_SCANCODE_S]) this->paddleDir +=  1;

}

void Game::generateOutput() {
	SDL_SetRenderDrawColor(this->gameRenderer, 0, 0, 255, 255);

	// Clear the back buffer 
	SDL_RenderClear(this->gameRenderer);

	// Draw output
	SDL_SetRenderDrawColor(this->gameRenderer, 255, 255, 255, 255);
	// Upper bound wall
	SDL_Rect upperWall{
		0,
		0,
		1024,
		thickness
	};
	// Lower bound wall
	SDL_Rect lowerWall{
		0,
		WINDOW_HEIGHT - thickness,
		WINDOW_WIDTH,
		thickness
	};
	// Right wall
	SDL_Rect rightWall{
		WINDOW_WIDTH - thickness,
		0,
		thickness,
		WINDOW_HEIGHT
	};
	SDL_Rect ball{
		static_cast<int>(this->BallPos.x - thickness / 2),
		static_cast<int>(this->BallPos.y - thickness / 2),
		thickness,
		thickness
	};
	SDL_Rect paddle{
		static_cast<int>(this->PaddlePos.x - thickness / 2),
		static_cast<int>(this->PaddlePos.y - 100 /2),
		thickness,
		100
	}; 
	SDL_RenderFillRect(this->gameRenderer, &upperWall);
	SDL_RenderFillRect(this->gameRenderer, &lowerWall);
	SDL_RenderFillRect(this->gameRenderer, &rightWall);
	SDL_RenderFillRect(this->gameRenderer, &ball);
	SDL_RenderFillRect(this->gameRenderer, &paddle);

	// Switch to front buffer
	SDL_RenderPresent(this->gameRenderer);
}	

void Game::updateGame() {
	// Wait until 16 ms has elapsed since last frame
	while (!SDL_TICKS_PASSED(SDL_GetTicks64(), this->ticksCounter + 16))
		;
	// Delta time is the difference in ticks from last frame
	float deltaTime = (SDL_GetTicks64() - this->ticksCounter) / 1000.0f;
	// Update tick counts for the next frame

	// Avoid too big delta time
	if (deltaTime > 0.05f) deltaTime = 0.05f;
	ticksCounter = SDL_GetTicks64();

	//Update game objects
	if (this->paddleDir != 0) {
		this->PaddlePos.y += this->paddleDir * 100.0f * deltaTime;
		if (this->PaddlePos.y < (PADDLE_HEIGHT / 2.0f + this->thickness))
			this->PaddlePos.y = PADDLE_HEIGHT / 2.0f + this->thickness;
		else if (this->PaddlePos.y > (WINDOW_HEIGHT - PADDLE_HEIGHT / 2.0f - this->thickness)) 
			this->PaddlePos.y = WINDOW_HEIGHT - PADDLE_HEIGHT / 2.0f - this->thickness;
	}
}

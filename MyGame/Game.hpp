#pragma once
#include "SDL.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Game {
private:
	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;
	bool isRunning;
	Vector2 leftPaddlePos;
	Vector2 rightPaddlePos;
	Vector2 BallPos;
	Vector2 BallVel;
	Uint64 ticksCounter;
	int leftPaddleDir;
	int rightPaddleDir;
	const int thickness = 15;

public:
 /**
     @brief Game object constructor
 **/
	Game();
 /**
     @brief 
 **/
	void runGameLoop();
 /**
     @brief 
 **/
	bool initializeGame();
 /**
     @brief 
 **/
	void shutDownGame();
 /**
	 @brief
 **/
	void processInput();
 /**
	 @brief
 **/
	void generateOutput();
 /**
	 @brief
 **/
	void updateGame();
 /**
	@brief
 **/
	void updatePaddle(float deltaTime, int paddleNumber);

};
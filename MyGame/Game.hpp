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
	Vector2 PaddlePos;
	Vector2 BallPos;

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

};
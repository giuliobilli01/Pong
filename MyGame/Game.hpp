#pragma once
#include "SDL.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Game {
private:


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



};
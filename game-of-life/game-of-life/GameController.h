#pragma once


#include "conio.h"


#include "World.h"


class GameController
{
private:
	World* world;

	bool isRunning;

public:
	GameController();
	~GameController();

	void runGame();
};


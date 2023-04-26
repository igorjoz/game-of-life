#pragma once


#include "conio.h"


#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Fox.h"
#include "Sheep.h"
#include "Tortoise.h"
#include "Grass.h"


class GameController
{
private:
	World* world;

	char playerInput;
	bool isRunning;
	int turn;

public:
	GameController();
	~GameController();

	void runGame();
	void takeTurn();

	void spawnInitialOrganisms();
	void createHuman();
	void spawnWolves();
	void spawnFoxes();
	void spawnSheep();
	void spawnTortoises();
	//void spawnAntelopes();
	void spawnGrass();

	void getInputFromPlayer();
	void handlePlayerInput();

	void printWelcomeMessage();
	void printStatistics();
	void printStatisticsAndThanksForPlayingMessage();
};

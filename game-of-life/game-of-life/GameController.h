#pragma once


#include "conio.h"


#include "World.h"
#include "Human.h"
#include "Wolf.h"
#include "Fox.h"
#include "Sheep.h"
#include "Tortoise.h"
#include "Antelope.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "PineBorscht.h"


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
	void spawnAntelopes();
	void spawnGrass();
	void spawnDandelions();
	void spawnGuarana();
	void spawnNightshade();
	void spawnPineBorscht();

	void getInputFromPlayer();
	void handlePlayerInput();

	void printWelcomeMessage();
	void printStatistics();
	void printStatisticsAndThanksForPlayingMessage();
};

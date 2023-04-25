#pragma once


#include "conio.h"


#include "World.h"
#include "Human.h"
#include "Wolf.h"


// Keys' codes
int const ARROW_UP = 72;
int const ARROW_DOWN = 80;
int const ARROW_LEFT = 75;
int const ARROW_RIGHT = 77;

int const ESC = 27;


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
	void spawnOrganism(Organism* organism, Point position);
	void createHuman();

	void getInputFromPlayer();
	void handlePlayerInput();

	void printWelcomeMessage();
	void printStatistics();
	void printStatisticsAndThanksForPlayingMessage();
};

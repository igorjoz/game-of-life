#pragma once


#include "conio.h"


#include "World.h"
#include "Human.h"


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

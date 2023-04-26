#pragma once


#include "conio.h"
#include "fstream"


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
	int turn;
	bool isRunning;

	int specialAbilityCooldown;
	bool isSpecialAbilityActive;

public:
	static int const SPECIAL_ABILITY_COOLDOWN = 5;

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

	void activateSpecialAbility();

	void saveToFile();
	void loadFromFile();
};

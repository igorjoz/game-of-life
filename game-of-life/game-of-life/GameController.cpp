#include "GameController.h"


GameController::GameController() :
	world { new World() },
	playerInput{ ' ' },
	isRunning{ true },
	turn{ 0 } {
}


GameController::~GameController() {
	delete world;
}


void GameController::runGame() {
	printWelcomeMessage();

	spawnInitialOrganisms();

	while (isRunning and world->getIsPlayerAlive()) {
		world->drawWorld();
		world->printTurnSummary();
		
		getInputFromPlayer();
		handlePlayerInput();

		if (!isRunning or !world->getIsPlayerAlive()) {
			break;
		}

		takeTurn();
	}

	printStatisticsAndThanksForPlayingMessage();
}


void GameController::takeTurn() {
	world->takeTurn();
	
	turn++;
}


void GameController::spawnInitialOrganisms() {
	createHuman();

	spawnWolves();
	spawnFoxes();

	spawnSheep();
	spawnTortoises();
	spawnAntelopes();
	
	spawnGrass();
	spawnDandelions();
	spawnGuarana();
	spawnNightshade();
	spawnPineBorscht();
}


void GameController::createHuman() {
	Point humanPosition = Point(0, 0);
	Human* human = new Human(humanPosition, *world);
	world->createHuman(human, humanPosition);
}


void GameController::spawnWolves() {
	for (int i = 0; i < Wolf::INITIAL_QUANTITY; i++) {
		Wolf* wolf = new Wolf(*world);
		world->spawnOrganism(wolf);
	}
}


void GameController::spawnFoxes() {
	for (int i = 0; i < Fox::INITIAL_QUANTITY; i++) {
		Fox* fox = new Fox(*world);
		world->spawnOrganism(fox);
	}
}


void GameController::spawnSheep() {
	for (int i = 0; i < Sheep::INITIAL_QUANTITY; i++) {
		Sheep* sheep = new Sheep(*world);
		world->spawnOrganism(sheep);
	}
}


void GameController::spawnTortoises() {
	for (int i = 0; i < Tortoise::INITIAL_QUANTITY; i++) {
		Tortoise* tortoise = new Tortoise(*world);
		world->spawnOrganism(tortoise);
	}
}


void GameController::spawnAntelopes() {
	for (int i = 0; i < Antelope::INITIAL_QUANTITY; i++) {
		Antelope* antelope = new Antelope(*world);
		world->spawnOrganism(antelope);
	}
}


void GameController::spawnGrass() {
	for (int i = 0; i < Grass::INITIAL_QUANTITY; i++) {
		Grass* grass = new Grass(*world);
		world->spawnOrganism(grass);
	}
}


void GameController::spawnDandelions() {
	for (int i = 0; i < Dandelion::INITIAL_QUANTITY; i++) {
		Dandelion* dandelion = new Dandelion(*world);
		world->spawnOrganism(dandelion);
	}
}


void GameController::spawnGuarana() {
	for (int i = 0; i < Guarana::INITIAL_QUANTITY; i++) {
		Guarana* guarana = new Guarana(*world);
		world->spawnOrganism(guarana);
	}
}


void GameController::spawnNightshade() {
	for (int i = 0; i < Nightshade::INITIAL_QUANTITY; i++) {
		Nightshade* nightshade = new Nightshade(*world);
		world->spawnOrganism(nightshade);
	}
}


void GameController::spawnPineBorscht() {
	for (int i = 0; i < PineBorscht::INITIAL_QUANTITY; i++) {
		PineBorscht* pineBorscht = new PineBorscht(*world);
		world->spawnOrganism(pineBorscht);
	}
}


void GameController::getInputFromPlayer() {
	playerInput = _getch();
	std::cout << playerInput << std::endl;

	if (playerInput <= 0 or playerInput == 224) {
		playerInput = _getch();
	}
}


void GameController::handlePlayerInput() {	
	Human* human = dynamic_cast<Human*> (world->getOrganismAt(world->getPlayerPosition()));
	
	switch (playerInput) {
		case 'q':
		case ESC: {
			isRunning = false;
			break;
		}

		case 'w':
		case ARROW_UP: {
			world->setPlayerAction(PlayerAction::MOVE_UP);
			human->setPlayerAction(PlayerAction::MOVE_UP);
			break;
		}

		case 's':
		case ARROW_DOWN: {
			world->setPlayerAction(PlayerAction::MOVE_DOWN);
			human->setPlayerAction(PlayerAction::MOVE_DOWN);
			break;
		}

		case 'a':
		case ARROW_LEFT: {
			world->setPlayerAction(PlayerAction::MOVE_LEFT);
			human->setPlayerAction(PlayerAction::MOVE_LEFT);
			break;
		}

		case 'd':
		case ARROW_RIGHT: {
			world->setPlayerAction(PlayerAction::MOVE_RIGHT);
			human->setPlayerAction(PlayerAction::MOVE_RIGHT);
			break;
		}

		case 'e': {
			world->setPlayerAction(PlayerAction::USE_SPECIAL_ABILITY);
			human->setPlayerAction(PlayerAction::USE_SPECIAL_ABILITY);
			break;
		}

		case 'k': {
			// save game to file
		}

		case 'l': {
			// load game from file
		}

		default: {
			break;
		}
	}
}


void GameController::printWelcomeMessage() {
		std::cout << "Welcome to the Game of Life!\n";
		std::cout << "Author: Igor Jozefowicz, 193257\n";
		std::cout << "----------------\n\n";

		std::cout << "Controls:\n";
		std::cout << "Press 'w' OR arrow up to move up\n";
		std::cout << "Press 's' OR arrow down to move down\n";
		std::cout << "Press 'a' OR arrow left to move left\n";
		std::cout << "Press 'd' OR arrow right to move right\n";
		std::cout << "Press 'q' OR ESC to quit\n\n";
		std::cout << "----------------\n\n";

		std::cout << "Press any key to start the game...\n";

		playerInput = _getch();
}


void GameController::printStatistics() {
	std::cout << "Statistics:\n";
	std::cout << "----------------\n";
	std::cout << "Turns: " << turn << "\n";
	std::cout << "----------------\n";
}


void GameController::printStatisticsAndThanksForPlayingMessage() {
	printStatistics();
	world->printStatistics();

	std::cout << "Thanks for playing!\n";
	std::cout << "Press any key to exit...\n";

	playerInput = _getch();
}

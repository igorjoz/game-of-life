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

	while (isRunning) {
		getInputFromPlayer();
		handlePlayerInput();

		if (!isRunning) {
			break;
		}

		world->drawWorld();
		world->printTurnSummary();
		takeTurn();
	}

	printStatisticsAndThanksForPlayingMessage();
}


void GameController::takeTurn() {
	// TODO: implement
	
	turn++;
}


void GameController::spawnInitialOrganisms() {
	//createHuman();
}


void GameController::spawnOrganism(Organism* organism, Point position) {
	// TODO: implement
}


void GameController::createHuman() {
	Point position = Point(0, 0);
	Human* human = new Human(5, 4, 'H', position, *world);
	
	world->createHuman(human, position);
}


void GameController::getInputFromPlayer() {
	playerInput = _getch();
}


void GameController::handlePlayerInput() {	
	switch (playerInput) {
		case 'q': {
			isRunning = false;
			break;
		}

		case 'w': {
			world->movePlayerUp();
			break;
		}

		case 's': {
			world->movePlayerDown();
			break;
		}

		case 'a': {
			world->movePlayerLeft();
			break;
		}

		case 'd': {
			world->movePlayerRight();
			break;
		}

		default: {
			break;
		}
	}
}


void GameController::printWelcomeMessage() {
		std::cout << "Welcome to the Game of Life!\n";
		std::cout << "Author: Igor Jozefowicz\n";
		std::cout << "----------------\n\n";

		std::cout << "Controls:\n";
		std::cout << "Press 'w' to move up\n";
		std::cout << "Press 's' to move down\n";
		std::cout << "Press 'a' to move left\n";
		std::cout << "Press 'd' to move right\n";
		std::cout << "Press 'q' to quit\n\n";
		std::cout << "----------------\n\n";

		std::cout << "Press any key to start the game...\n";
}


void GameController::printStatistics() {
	std::cout << "Statistics:\n";
	std::cout << "----------------\n";
	std::cout << "Turns: " << turn << std::endl;
	std::cout << "----------------\n";
}


void GameController::printStatisticsAndThanksForPlayingMessage() {
	printStatistics();
	world->printStatistics();

	std::cout << "Thanks for playing!\n";
	std::cout << "Press any key to exit...\n";

	playerInput = _getch();
}

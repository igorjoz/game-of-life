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
	createHuman();
}


void GameController::spawnOrganism(Organism* organism, Point position) {
	// TODO: implement
}


void GameController::createHuman() {
	Point humanPosition = Point(0, 0);
	Human* human = new Human(humanPosition, *world);
	world->createHuman(human, humanPosition);

	//Point wolfPosition = Point(1, 1);
	Wolf* wolf = new Wolf(*world);
	world->spawnOrganism(wolf);
}


void GameController::getInputFromPlayer() {
	playerInput = _getch();
}


void GameController::handlePlayerInput() {	
	switch (playerInput) {
		case 'q':
		case ESC: {
			isRunning = false;
			break;
		}

		case 'w':
		case ARROW_UP: {
			world->movePlayerUp();
			break;
		}

		case 's':
		case ARROW_DOWN: {
			world->movePlayerDown();
			break;
		}

		case 'a':
		case ARROW_LEFT: {
			world->movePlayerLeft();
			break;
		}

		case 'd':
		case ARROW_RIGHT: {
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
		std::cout << "Author: Igor Jozefowicz, 193257\n";
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

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
		world->drawWorld();
		world->printTurnSummary();
		
		getInputFromPlayer();
		handlePlayerInput();

		if (!isRunning) {
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

	//Point wolfPosition = Point(1, 1);
	Wolf* wolf = new Wolf(*world);
	world->spawnOrganism(wolf);
}


void GameController::spawnOrganism(Organism* organism, Point position) {
	// TODO: implement
}


void GameController::createHuman() {
	Point humanPosition = Point(0, 0);
	Human* human = new Human(humanPosition, *world);
	world->createHuman(human, humanPosition);
}


void GameController::getInputFromPlayer() {
	playerInput = _getch();
	std::cout << playerInput << std::endl;

	if (playerInput <= 0 or playerInput == 224) {
		playerInput = _getch();
	}
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

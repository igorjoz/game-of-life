#include "GameController.h"


GameController::GameController() :
	world { new World() },
	isRunning{ true } {
}


GameController::~GameController() {
	delete world;
}


void GameController::runGame() {
	// press 'q' to quit
	std::cout << "Press 'q' to quit" << std::endl;
	// cout isRunning
	std::cout << "isRunning: " << isRunning << std::endl;

	while (isRunning) {
		// get user input
		
		char playerInput = _getch();

		if (playerInput == 'q') {
			isRunning = false;
			break;
		}

		world->drawWorld();
		world->takeTurn();
	}
}

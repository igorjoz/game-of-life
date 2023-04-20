#include "GameController.h"


GameController::GameController() :
	world { new World() },
	isRunning{ true } {
}


GameController::~GameController() {
	delete world;
}


void GameController::runGame() {
	std::cout << "Press 'q' to quit" << std::endl;

	while (isRunning) {
		char playerInput = _getch();

		if (playerInput == 'q') {
			isRunning = false;
			break;
		}

		world->drawWorld();
		world->takeTurn();
	}
}

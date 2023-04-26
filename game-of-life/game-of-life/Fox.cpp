#include "Fox.h"


Fox::Fox(const Point& position, World& world) : PredatorAnimal(STRENGTH, INITIATIVE, SYMBOL, position, world) {
}


Fox::Fox(World& world) : PredatorAnimal(STRENGTH, INITIATIVE, SYMBOL, world) {
}


Fox::~Fox() {
}


bool Fox::collision(Organism& other) {
	if (canKill(other)) {
		kill(other);

		return true;
	}

	if (canReproduce(other, position)) {
		reproduce(position);
	}

	return false;
}


void Fox::reproduce(const Point& position) {
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Fox* newOrganism = new Fox(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);


	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}

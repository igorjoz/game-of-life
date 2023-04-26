#include "Wolf.h"


Wolf::Wolf(const Point& position, World& world) :
	PredatorAnimal(STRENGTH, INITIATIVE, SYMBOL, position, world) {
}


Wolf::Wolf(World& world) :
	PredatorAnimal(STRENGTH, INITIATIVE, SYMBOL, world) {
}


Wolf::~Wolf() {
}


void Wolf::reproduce(const Point& position) {
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Wolf* newOrganism = new Wolf(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);
	

	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}

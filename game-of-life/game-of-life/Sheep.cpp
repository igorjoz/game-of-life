#include "Sheep.h"


Sheep::Sheep(const Point& position, World& world) :
	PreyAnimal(STRENGTH, INITIATIVE, SYMBOL, position, world) {
	species = Species::SHEEP;
}


Sheep::Sheep(World& world) :
	PreyAnimal(STRENGTH, INITIATIVE, SYMBOL, world) {
	species = Species::SHEEP;
}


Sheep::~Sheep() {
}


void Sheep::reproduce(const Point& position) {
	if (rand() % 3 != 0) {
		return;
	}
	
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Sheep* newOrganism = new Sheep(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);

	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}

#include "Guarana.h"


Guarana::Guarana(const Point& position, World& world) :
	Plant(STRENGTH, SYMBOL, position, world) {
}


Guarana::Guarana(World& world) :
	Plant(STRENGTH, SYMBOL, world) {
}


Guarana::~Guarana() {
}


void Guarana::reproduce(const Point& position) {
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Guarana* newOrganism = new Guarana(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);

	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


bool Guarana::collision(Organism& other) {
	if (canBeKilledBy(other)) {
		other.setStrength(other.getStrength() + 3);

		std::string message = "Organism " + std::string(1, other.getSymbol()) + " ate guarana at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

		world.addTurnSummaryMessage(message);

		die();

		return true;
	}

	return false;
}

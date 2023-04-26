#include "Nightshade.h"


Nightshade::Nightshade(const Point& position, World& world) :
	Plant(STRENGTH, SYMBOL, position, world) {
	species = Species::NIGHTSHADE;
}


Nightshade::Nightshade(World& world) :
	Plant(STRENGTH, SYMBOL, world) {
	species = Species::NIGHTSHADE;
}


Nightshade::~Nightshade() {
}


void Nightshade::reproduce(const Point& position) {
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Nightshade* newOrganism = new Nightshade(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);

	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


bool Nightshade::collision(Organism& other) {
	other.die();

	std::string message = "Organism " + std::string(1, other.getSymbol()) + " ate nightshade at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);

	die();

	return true;
}


bool Nightshade::canReproduceThisTurn() const {
	return false;
}


bool Nightshade::canKill(const Organism& other) const {
	return true;
}

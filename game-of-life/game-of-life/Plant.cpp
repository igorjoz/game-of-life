#include "Plant.h"


Plant::Plant(char symbol, const Point& position, World& world) :
	Organism(0, INITIATIVE, symbol, position, world) {
	species = Species::PLANT;
}


Plant::Plant(int strength, char symbol, const Point& position, World& world) :
	Organism(strength, INITIATIVE, symbol, position, world) {
	species = Species::PLANT;
}


Plant::Plant(int strength, char symbol, World& world) :
	Organism(strength, INITIATIVE, symbol, world) {
	species = Species::PLANT;
}


Plant::~Plant() {
}


void Plant::action() {
	if (canReproduceThisTurn() and hasFreeSpace()) {
		Point position = world.getRandomFreeSpaceAround(this->position);
		reproduce(position);
	}
}


bool Plant::collision(Organism& other) {
	/*if (canEat(other)) {
		eat(other);
		return true;
	}

	return false;*/

	return false;
}


void Plant::draw() {
}


void Plant::die() {
	world.remove(position);
}


void Plant::kill(Organism& other) {
	other.die();

	std::string message = "Organism " + std::string(1, other.getSymbol()) + " was killed by " + std::string(1, symbol) + " at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


bool Plant::canKill(const Organism& other) const {
	return false;
}


bool Plant::canBeKilledBy(const Organism& other) const {
	if (typeid(*this) == typeid(other)) {
		return false;
	}
	
	return other.getStrength() >= strength;
}


bool Plant::hasFreeSpace() const {
	return world.hasFreeSpace(position);
}


bool Plant::canReproduceThisTurn() const {
	return (rand() % 12 == 0);
}


void Plant::reproduce(const Point& position) {
}

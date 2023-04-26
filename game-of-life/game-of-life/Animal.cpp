#include "Animal.h"


Animal::Animal(int strength, int initiative, char symbol, const Point& position, World& world) :
	Organism(strength, initiative, symbol, position, world) {
	isAnimal = true;
}


Animal::Animal(int strength, int initiative, char symbol, World& world) : Organism(strength, initiative, symbol, world) {
	isAnimal = true;
}


Animal::~Animal() {
}


void Animal::action() {
	Point destination = world.getRandomNeighbour(position);
	
	if (!world.isWithinBoardBoundaries(destination)) {
		return;
	}

	if (canMoveTo(destination)) {
		move(destination);
		
		return;
	}

	if (world.isOccupied(destination)) {
		Organism* other = world.getOrganismAt(destination);

		collision(*other);
	}
}


bool Animal::collision(Organism& other) {
	if (canKill(other)) {
		kill(other);
		
		return true;
	}
	//else {
		other.collision(*this);
	//}

	if (canReproduce(other, position)) {
		reproduce(position);
	}
	
	return false;
}


void Animal::draw() {
}


void Animal::move(const Point& destination) {
	world.move(position, destination);
	position = destination;
}


void Animal::kill(Organism& other) {
	other.die();

	std::string message = "Organism " + std::string(1, other.getSymbol()) + " was killed by " + std::string(1, symbol) + " at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


void Animal::reproduce(const Point& position) {
	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


void Animal::die() {
	world.remove(position);
}


bool Animal::canMoveTo(const Point& destination) const {
	bool canMoveTo = world.isEmpty(destination);

	if (destination.x < 0 or destination.x >= WORLD_SIZE or destination.y < 0 or destination.y >= WORLD_SIZE) {
		canMoveTo = false;
	}
	
	return canMoveTo;
}


bool Animal::canKill(const Organism& other) const {
	if (typeid(*this) == typeid(other)) {
		return false;
	}

	return other.canBeKilledBy(*this);
}


bool Animal::canBeKilledBy(const Organism& other) const {
	if (typeid(*this) == typeid(other)) {
		return false;
	}

	return strength < other.getStrength();
}


bool Animal::canReproduce(const Organism& other, const Point& position) const {
	if (typeid(*this) == typeid(other) and world.hasFreeSpace(position)) {
		return true;
	}

	return false;
}

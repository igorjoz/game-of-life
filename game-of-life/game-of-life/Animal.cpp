#include "Animal.h"


Animal::Animal(int strength, int initiative, char symbol, const Point& position, World& world) :
	Organism(strength, initiative, symbol, position, world) {
}


Animal::Animal(int strength, int initiative, char symbol, World& world) :
	Organism(strength, initiative, symbol, world) {
}


Animal::~Animal() {
}


void Animal::action() {
	Point destination = world.getRandomNeighbour(position);
	if (canMoveTo(destination)) {
		move(destination);
	}
}


bool Animal::collision(Organism& other) {
	if (canEat(other)) {
		eat(other);
		
		return true;
	}
	else {
		other.collision(*this);
	}
	
	return false;
}


void Animal::move(const Point& destination) {
	world.move(position, destination);
	position = destination;
}


void Animal::eat(Organism& other) {
	world.remove(other.getPosition());

	std::string message = "Organism " + std::string(1, other.getSymbol()) + " was eaten by " + std::string(1, symbol) + " at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


void Animal::reproduce(const Point& position) {
	// TODO
}


bool Animal::canMoveTo(const Point& destination) const {
	bool canMoveTo = world.isEmpty(destination);

	/*if (canMoveTo) {
		Organism* other = world.getOrganism(destination);
		if (other != nullptr) {
			canMoveTo = canEat(*other);
		}
	}*/

	if (destination.x < 0 or destination.x >= WORLD_SIZE or destination.y < 0 or destination.y >= WORLD_SIZE) {
		canMoveTo = false;
	}
	
	return canMoveTo;
}


bool Animal::canEat(const Organism& other) const {
	if (typeid(*this) == typeid(other)) {
		return false;
	}

	return strength > other.getStrength();
}

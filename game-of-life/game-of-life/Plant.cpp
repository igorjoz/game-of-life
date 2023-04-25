#include "Plant.h"


Plant::Plant(char symbol, const Point& position, World& world) :
	Organism(0, INITIATIVE, symbol, position, world) {
}


Plant::Plant(int strength, char symbol, const Point& position, World& world) :
	Organism(strength, INITIATIVE, symbol, position, world) {
}


Plant::Plant(int strength, char symbol, World& world) :
	Organism(strength, INITIATIVE, symbol, world) {
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
	//world.draw(position, symbol);
}


void Plant::die() {
	world.remove(position);
}


bool Plant::hasFreeSpace() const {
	return world.hasFreeSpace(position);
}


bool Plant::canReproduceThisTurn() const {
	return (rand() % 12 == 0);
}


void Plant::reproduce(const Point& position) {
}

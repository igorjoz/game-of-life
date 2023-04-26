#include "PredatorAnimal.h"


PredatorAnimal::PredatorAnimal(int strength, int initiative, char symbol, const Point& position, World& world) :
	Animal(strength, initiative, symbol, position, world) {
}


PredatorAnimal::PredatorAnimal(int strength, int initiative, char symbol, World& world) :
	Animal(strength, initiative, symbol, world) {
}


PredatorAnimal::~PredatorAnimal() {
}


void PredatorAnimal::action() {
	Point destination = world.getRandomNeighbour(position);
	
	if (!world.isWithinBoardBoundaries(destination)) {
		return;
	}

	if (world.isOccupied(destination)) {
		Organism* other = world.getOrganismAt(destination);

		collision(*other);
	}

	if (canMoveTo(destination)) {
		move(destination);
	}
}


bool PredatorAnimal::collision(Organism& other) {
	if (canReproduce(other, position)) {
		reproduce(position);

		return true;
	}
	
	if (canKill(other)) {
		kill(other);

		return true;
	}
	else if (other.canKill(*this)) {
		other.kill(*this);
	}

	return false;
}


void PredatorAnimal::reproduce(const Point& position) {
	if (rand() % 2 == 0) {
		return;
	}
	
	Animal::reproduce(position);
}

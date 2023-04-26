#include "PreyAnimal.h"


PreyAnimal::PreyAnimal(int strength, int initiative, char symbol, const Point& position, World& world) :
	Animal(strength, initiative, symbol, position, world) {
}


PreyAnimal::PreyAnimal(int strength, int initiative, char symbol, World& world) :
	Animal(strength, initiative, symbol, world) {
}


PreyAnimal::~PreyAnimal() {
}


void PreyAnimal::action() {
	Point destination = world.getRandomNeighbour(position);

	if (!world.isWithinBoardBoundaries(destination)) {
		return;
	}
	
	if (world.isOccupied(destination)) {
		Organism* other = world.getOrganismAt(destination);

		collision(*other);

		return;
	}

	if (canMoveTo(destination)) {
		move(destination);

		return;
	}
}


bool PreyAnimal::collision(Organism& other) {
	if (canReproduce(other, position)) {
		reproduce(position);

		return true;
	}
	
	if (other.canBeKilledBy(*this)) {
		kill(other);

		return true;
	}
	else if (other.canKill(*this)) {
		other.collision(*this);

		return true;
	}

	return false;
}

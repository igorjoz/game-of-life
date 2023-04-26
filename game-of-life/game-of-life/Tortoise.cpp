#include "Tortoise.h"


Tortoise::Tortoise(const Point& position, World& world) :
	PreyAnimal(STRENGTH, INITIATIVE, SYMBOL, position, world) {
}


Tortoise::Tortoise(World& world) :
	PreyAnimal(STRENGTH, INITIATIVE, SYMBOL, world) {
}


Tortoise::~Tortoise() {
}


void Tortoise::reproduce(const Point& position) {
	if (rand() % 3 != 0) {
		return;
	}
	
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Tortoise* newOrganism = new Tortoise(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);


	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);
}


bool Tortoise::collision(Organism& other) {
	if (canReproduce(other, position)) {
		reproduce(position);

		return true;
	}
	
	if (canKill(other)) {
		kill(other);

		return true;
	}
	else {
		other.collision(*this);
		
		return true;
	}

	return false;
}


void Tortoise::action() {
	if (rand() % 4 == 0) {
		return;
	}

	PreyAnimal::action();
}


bool Tortoise::canBeKilledBy(const Organism& other) const {
	if (typeid(*this) == typeid(other)) {
		return false;
	}

	return strength < other.getStrength() and other.getStrength() > 5;
}

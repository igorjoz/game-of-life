#include "Antelope.h"


Antelope::Antelope(const Point& position, World& world) : PreyAnimal{ STRENGTH, INITIATIVE, SYMBOL, position, world } {
	species = Species::ANTELOPE;
}


Antelope::Antelope(World& world) : PreyAnimal{ STRENGTH, INITIATIVE, SYMBOL, world } {
	species = Species::ANTELOPE;
}


Antelope::~Antelope() {
}


void Antelope::reproduce(const Point& position) {
	Point freeSpace = world.getRandomFreeSpaceAround(position);

	Antelope* newOrganism = new Antelope(freeSpace, world);
	world.setOrganism(newOrganism, freeSpace);
	
	std::string message = "Organism " + std::string(1, symbol) + " reproduced at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

	world.addTurnSummaryMessage(message);

}


void Antelope::action() {
	// antelope can move 2 fields in one turn
	for (int i = 0; i < 2; i++) {
		Point destination = world.getRandomFreeSpaceAround(position);

		if (destination != position) {
			move(destination);
		}
	}
}


bool Antelope::collision(Organism& other) {
	if (canReproduce(other, position)) {
		reproduce(position);

		return true;
	}
	
	if (other.canBeKilledBy(*this)) {
		kill(other);

		return true;
	}
	else if (other.canKill(*this)) {
		if (rand() % 2 == 0) {
			Point freeSpace = world.getRandomFreeSpaceAround(position);

			if (freeSpace != position) {
				move(freeSpace);
			}

			std::string message = "Organism " + std::string(1, symbol) + " escaped from fight at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";
			world.addTurnSummaryMessage(message);
			
			return true;
		}
		
		other.collision(*this);

		return true;
	}

	

	return false;
}


void Antelope::die() {
	if (rand() % 2 == 0) {
		Point freeSpace = world.getRandomFreeSpaceAround(position);
		
		if (freeSpace == position) {
			world.remove(position);
		}

		move(freeSpace);

		std::string message = "Organism " + std::string(1, symbol) + " escaped from fight at (" + std::to_string(position.x) + ", " + std::to_string(position.y) + ")";

		world.addTurnSummaryMessage(message);

		return;
	}

	world.remove(position);
}

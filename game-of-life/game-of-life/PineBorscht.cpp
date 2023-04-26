#include "PineBorscht.h"


PineBorscht::PineBorscht(const Point& position, World& world)
	: Plant(STRENGTH, SYMBOL, position, world) {
	species = Species::PINE_BORSCHT;
}


PineBorscht::PineBorscht(World& world)
	: Plant(STRENGTH, SYMBOL, world) {
	species = Species::PINE_BORSCHT;
}


PineBorscht::~PineBorscht() {
}


bool PineBorscht::canKill(const Organism& other) const {
	return true;
}


bool PineBorscht::canReproduceThisTurn() const
{
	return false;
}


void PineBorscht::action() {
	int x = position.x;
	int y = position.y;

	Point destination(x - 1, y);
	if (world.isWithinBoardBoundaries(destination) and world.isOccupied(destination)) {
		Organism* organism = world.getOrganismAt(destination);
		if (organism != nullptr) {
			kill(*organism);
		}
	}

	destination = Point(x, y - 1);
	if (world.isWithinBoardBoundaries(destination) and world.isOccupied(destination)) {
		Organism* organism = world.getOrganismAt(destination);
		if (organism != nullptr) {
			kill(*organism);
		}
	}

	destination = Point(x + 1, y);
	if (world.isWithinBoardBoundaries(destination) and world.isOccupied(destination)) {
		Organism* organism = world.getOrganismAt(destination);
		if (organism != nullptr) {
			kill(*organism);
		}
	}
	
	destination = Point(x, y + 1);
	if (world.isWithinBoardBoundaries(destination) and world.isOccupied(destination)) {
		Organism* organism = world.getOrganismAt(destination);
		if (organism != nullptr) {
			kill(*organism);
		}
	}
	
	/*for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			Point destination(i, j);

			if (!world.isWithinBoardBoundaries(destination) and !world.isOccupied(destination)) {
				continue;
			}

			if (world.isOccupied(destination)) {
				Organism* organism = world.getOrganismAt(destination);
				if (organism != nullptr) {
					kill(*organism);
				}
			}
		}
	}*/
}


bool PineBorscht::collision(Organism& other) {
	kill(other);
	
	return true;
}

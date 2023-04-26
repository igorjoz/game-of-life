#include "PineBorscht.h"


PineBorscht::PineBorscht(const Point& position, World& world)
	: Plant(STRENGTH, SYMBOL, position, world) {
}


PineBorscht::PineBorscht(World& world)
	: Plant(STRENGTH, SYMBOL, world) {
}


PineBorscht::~PineBorscht() {
}


bool PineBorscht::canReproduceThisTurn() const
{
	return false;
}


void PineBorscht::action() {
	int x = position.x;
	int y = position.y;
	
	for (int i = x - 1; i <= x + 1; i++) {
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
	}
}


bool PineBorscht::collision(Organism& other) {
	kill(other);
	return true;
}

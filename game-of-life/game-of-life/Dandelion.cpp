#include "Dandelion.h"


Dandelion::Dandelion(const Point& position, World& world) :
	Plant(STRENGTH, SYMBOL, position, world) {
	species = Species::DANDELION;
}


Dandelion::Dandelion(World& world) :
	Plant(STRENGTH, SYMBOL, world) {
	species = Species::DANDELION;
}


Dandelion::~Dandelion() {
}


void Dandelion::reproduce(const Point& position) {
	for (int i = 0; i < 3; i++) {
		Point position = world.getRandomFreeSpaceAround(this->position);
		
		Plant* plant = new Dandelion(position, world);
		world.setOrganism(plant, plant->getPosition());
	}
}


bool Dandelion::canReproduceThisTurn() const {
	return (rand() % 32 == 0);
}
#include "Grass.h"


Grass::Grass(World& world) :
	Plant(STRENGTH, SYMBOL, world) {
	species = Species::GRASS;
}


Grass::Grass(const Point& position, World& world) :
	Plant(STRENGTH, SYMBOL, position, world) {
	species = Species::GRASS;
}


Grass::~Grass() {
}


void Grass::reproduce(const Point& position) {
	Grass* child = new Grass(position, world);
	world.setOrganism(child, position);
}
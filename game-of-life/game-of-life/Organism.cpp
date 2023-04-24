#include "Organism.h"


Organism::Organism(World& world) :
	strength{ 0 },
	initiative{ 0 },
	age{ 0 },
	symbol{ 'N' },
	position{ Point(0, 0) },
	world(world) {
}


Organism::Organism(int strength, int initiative, char symbol, Point position, World& world) :
	strength{ strength },
	initiative{ initiative },
	age{ 0 },
	symbol{ symbol },
	position{ position },
	world{ world } {
}


Organism::Organism(int strength, int initiative, int age, char symbol, Point position, World& world) :
	strength{ strength },
	initiative{ initiative },
	age{ age },
	symbol{ symbol },
	position{ position },
	world{ world } {
}


Organism::~Organism() {
}


int Organism::getStrength() const {
	return strength;
}


int Organism::getInitiative() const {
	return initiative;
}


int Organism::getAge() const {
	return age;
}


char Organism::getSymbol() const {
	return symbol;
}


Point& Organism::getPosition() {
	return position;
}


int Organism::getX() const {
	return position.x;
}


int Organism::getY() const {
	return position.y;
}


void Organism::setPosition(int x, int y) {
	position.x = x;
	position.y = y;
}


void Organism::setPosition(Point& position) {
	this->position = position;
}

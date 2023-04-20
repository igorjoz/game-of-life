#include "PredatorAnimal.h"


PredatorAnimal::PredatorAnimal(int strength, int initiative, char symbol, const Point& position, World& world) :
	Animal(strength, initiative, symbol, position, world) {
}


PredatorAnimal::~PredatorAnimal() {
}


void PredatorAnimal::action() {
	Point destination = world.getRandomNeighbour(position);
	
	if (canMoveTo(destination)) {
		move(destination);
	}
}


bool PredatorAnimal::collision(Organism& other) {
	if (canEat(other)) {
		eat(other);
		return true;
	}
	return false;
}

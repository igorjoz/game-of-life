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
	
	if (canMoveTo(destination)) {
		move(destination);
	}
}


bool PredatorAnimal::collision(Organism& other) {
	return Animal::collision(other);

	/*if (canEat(other)) {
		eat(other);
		return true;
	}
	
	return false;*/
}


void PredatorAnimal::draw() {
	//world.draw(position, symbol);
}


void PredatorAnimal::move(const Point& position) {
	Animal::move(position);
}


void PredatorAnimal::eat(Organism& other) {
	Animal::eat(other);
}


void PredatorAnimal::reproduce(const Point& position) {
	Animal::reproduce(position);
}


bool PredatorAnimal::canMoveTo(const Point& destination) const {
	return Animal::canMoveTo(destination);
}


bool PredatorAnimal::canEat(const Organism& other) const {
	return Animal::canEat(other);
}

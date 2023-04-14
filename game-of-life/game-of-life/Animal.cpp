#include "Animal.h"


Animal::Animal(int strength, int initiative, char symbol, const Point& position, World& world) :
	Organism(strength, initiative, symbol, position, world) {
}


Animal::~Animal() {
}


void Animal::action() {
	Point destination = world.getRandomNeighbour(position);
	if (canMoveTo(destination)) {
		move(destination);
	}
}


bool Animal::collision(Organism& other) {
	if (canEat(other)) {
		eat(other);
		return true;
	}
	return false;
}


//void Animal::draw() {
//	world.draw(position, symbol);
//}


void Animal::move(const Point& destination) {
	world.move(position, destination);
	position = destination;
}


void Animal::eat(Organism& other) {
	world.remove(other.getPosition());
}


void Animal::reproduce(const Point& position) {
	// TODO
}


bool Animal::canMoveTo(const Point& destination) const {
	return world.isEmpty(destination);
}


bool Animal::canEat(const Organism& other) const {
	return false;
}

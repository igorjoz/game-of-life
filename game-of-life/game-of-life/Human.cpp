#include "Human.h"


Human::Human(const Point& position, World& world) :
	PredatorAnimal(5, 4, 'H', position, world), specialAbilityCooldown{ 0 } {
}


Human::~Human() {
}


void Human::action() {
	Point destination = world.getRandomNeighbour(position);

	if (canMoveTo(destination)) {
		move(destination);
	}
}


bool Human::collision(Organism& other) {
	if (canEat(other)) {
		eat(other);
		return true;
	}
	return false;
}


void Human::draw() {
	//world.draw(position, symbol);
}


void Human::activateSpecialAbility(SpecialAbility specialAbility) {
	// TODO: implement this
}


void Human::move(const Point& position) {
	Animal::move(position);
}


void Human::eat(Organism& other) {
	Animal::eat(other);
}


void Human::reproduce(const Point& position) {
	Animal::reproduce(position);
}


bool Human::canMoveTo(const Point& destination) const {
	return Animal::canMoveTo(destination);
}


bool Human::canEat(const Organism& other) const {
	return Animal::canEat(other);
}

#include "Human.h"


Human::Human(const Point& position, World& world) :
	PredatorAnimal(HUMAN_STRENGTH, HUMAN_INITIATIVE, HUMAN_SYMBOL, position, world), specialAbilityCooldown{ 0 } {
}


Human::~Human() {
}


void Human::action() {
	// Human is controlled by the player, so it shouldn't have action method implemented
	
	//Point destination = world.getRandomNeighbour(position);

	//if (canMoveTo(destination)) {
	//	move(destination);
	//}
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

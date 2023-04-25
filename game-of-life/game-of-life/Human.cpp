#include "Human.h"


Human::Human(const Point& position, World& world) :
	PredatorAnimal(STRENGTH, INITIATIVE, SYMBOL, position, world), specialAbilityCooldown{ 0 }, playerAction{ PlayerAction::NONE } {
}


Human::~Human() {
}


void Human::action() {
	if (specialAbilityCooldown > 0) {
		specialAbilityCooldown--;
	}

	Point destination;

	if (playerAction == PlayerAction::MOVE_UP) {
		destination = Point(position.x, position.y - 1);
	}
	else if (playerAction == PlayerAction::MOVE_DOWN) {
		destination = Point(position.x, position.y + 1);
	}
	else if (playerAction == PlayerAction::MOVE_LEFT) {
		destination = Point(position.x - 1, position.y);
	}
	else if (playerAction == PlayerAction::MOVE_RIGHT) {
		destination = Point(position.x + 1, position.y);
	}

	if (!world.isWithinBoardBoundaries(destination)) {
		return;
	}

	if (canMoveTo(destination)) {
		move(destination);

		//return;
	}

	if (world.isOccupied(destination)) {
		Organism* other = world.getOrganismAt(destination);

		if (collision(*other)) {
			return;
		}
	}

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


void Human::die() {
	Animal::die();

	world.setIsPlayerAlive(false);
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

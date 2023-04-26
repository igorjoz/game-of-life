#include "Human.h"


Human::Human(const Point& position, World& world) :
	Animal(STRENGTH, INITIATIVE, SYMBOL, position, world), specialAbilityCooldown{ 0 }, playerAction{ PlayerAction::NONE } {
}


Human::~Human() {
}


void Human::action() {
	if (specialAbilityCooldown > 0) {
		specialAbilityCooldown--;
	}

	int x = position.x;
	int y = position.y;

	if (playerAction == PlayerAction::MOVE_UP) {
		y -= 1;
	}
	else if (playerAction == PlayerAction::MOVE_DOWN) {
		y += 1;
	}
	else if (playerAction == PlayerAction::MOVE_LEFT) {
		x -= 1;
	}
	else if (playerAction == PlayerAction::MOVE_RIGHT) {
		x += 1;
	}

	Point destination(x, y);

	if (!world.isWithinBoardBoundaries(destination)) {
		return;
	}

	if (world.isOccupied(destination)) {
		Organism* other = world.getOrganismAt(destination);
		
		collision(*other);
	}

	if (canMoveTo(destination)) {
		move(destination);
		world.setPlayerPosition(x, y);
	}
}


bool Human::collision(Organism& other) {
	if (canKill(other)) {
		kill(other);
		
		return true;
	}
	
	return false;
}


void Human::draw() {
	//world.draw(position, symbol);
}


void Human::die() {
	world.setIsPlayerAlive(false);
	
	Animal::die();
}


void Human::activateSpecialAbility(SpecialAbility specialAbility) {
	// TODO: implement this
}


//void Human::move(const Point& position) {
//	Animal::move(position);
//}


void Human::kill(Organism& other) {
	Animal::kill(other);
}


void Human::reproduce(const Point& position) {
	Animal::reproduce(position);
}


bool Human::canMoveTo(const Point& destination) const {
	return Animal::canMoveTo(destination);
}


bool Human::canKill(const Organism& other) const {
	return Animal::canKill(other);
}


PlayerAction Human::getPlayerAction() const {
	return playerAction;
}


void Human::setPlayerAction(PlayerAction playerAction) {
	this->playerAction = playerAction;
}

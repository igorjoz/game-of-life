#include "Wolf.h"


Wolf::Wolf(const Point& position, World& world) :
	PredatorAnimal(WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SYMBOL, position, world) {
}


Wolf::Wolf(World& world) :
	PredatorAnimal(WOLF_STRENGTH, WOLF_INITIATIVE, WOLF_SYMBOL, world) {
}


Wolf::~Wolf() {
}


void Wolf::draw() {
	//world.draw(position, symbol);
}


//void Wolf::move(const Point& position) {
//	PredatorAnimal::move(position);
//}
//
//
//void Wolf::eat(Organism& other) {
//	PredatorAnimal::eat(other);
//}
//
//
//bool Wolf::canMoveTo(const Point& destination) const {
//	return PredatorAnimal::canMoveTo(destination);
//}
//
//
//bool Wolf::canEat(const Organism& other) const {
//	return PredatorAnimal::canEat(other);
//}
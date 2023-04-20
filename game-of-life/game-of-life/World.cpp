#include "World.h"


World::World() {
	for (int i = 0; i < WORLD_SIZE; i++) {
		for (int j = 0; j < WORLD_SIZE; j++) {
			organisms[i][j] = nullptr;
		}
	}
}


World::~World() {
	for (int i = 0; i < WORLD_SIZE; i++) {
		for (int j = 0; j < WORLD_SIZE; j++) {
			if (organisms[i][j] != nullptr) {
				delete organisms[i][j];
			}
		}
	}
}


void World::drawWorld() {
	system("cls");

	drawHorizontalBorder();
	
	for (int i = 0; i < WORLD_SIZE; i++) {
		std::cout << "#";
		for (int j = 0; j < WORLD_SIZE; j++) {
			if (organisms[i][j] != nullptr) {
				std::cout << organisms[i][j]->getSymbol();
			}
			//else {
			//	//std::cout << " ";
			//	std::cout << (i + 1)(j + 1);
			//}
		}
		std::cout << "#" << std::endl;
	}

	drawHorizontalBorder();
}


void World::drawHorizontalBorder() {
	for (int i = 0; i < WORLD_SIZE + 2; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;
}


void World::takeTurn() {
}


void World::move(Point position, Point destination) {
	organisms[destination.x][destination.y] = organisms[position.x][position.y];
	organisms[position.x][position.y] = nullptr;
}


void World::remove(Point position) {
	if (organisms[position.x][position.y] != nullptr) {
		delete organisms[position.x][position.y];
		organisms[position.x][position.y] = nullptr;
	}
}


bool World::isEmpty(Point position) {
	return organisms[position.x][position.y] == nullptr;
}


Point World::getRandomNeighbour(const Point& position) const {
	int random = rand() % 4;

	switch (random) {
	case 0:
		return Point(position.x, position.y - 1);
	case 1:
		return Point(position.x, position.y + 1);
	case 2:
		return Point(position.x - 1, position.y);
	case 3:
		return Point(position.x + 1, position.y);
	default:
		return Point(0, 0);
	}
}

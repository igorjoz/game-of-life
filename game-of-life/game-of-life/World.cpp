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
		std::cout << "# ";

		for (int j = 0; j < WORLD_SIZE; j++) {
			if (organisms[i][j] != nullptr) {
				std::cout << organisms[i][j]->getSymbol() << " ";
			}
			else {
				std::cout << "  ";
			}
		}

		std::cout << "# " << std::endl;
	}

	drawHorizontalBorder();
}


void World::drawHorizontalBorder() {
	for (int i = 0; i < WORLD_SIZE + 2; i++) {
		std::cout << "# ";
	}

	std::cout << std::endl;
}


void World::spawnOrganism(Organism* organism) {
	int x = rand() % WORLD_SIZE;
	int y = rand() % WORLD_SIZE;
	while (organisms[x][y] != nullptr) {
		x = rand() % WORLD_SIZE;
		y = rand() % WORLD_SIZE;
	}
	organisms[x][y] = organism;
	organisms[x][y]->getPosition().x = x;
	organisms[x][y]->getPosition().y = y;
}


void World::spawnOrganism(Organism* organism, Point position) {
	organisms[position.x][position.y] = organism;
	organisms[position.x][position.y]->getPosition().x = position.x;
	organisms[position.x][position.y]->getPosition().y = position.y;
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


void World::movePlayerUp() {
	if (organisms[playerPosition.x][playerPosition.y - 1] != nullptr) {
		//organisms[playerPosition.x][playerPosition.y - 1]->interact();
	}
	else {
		move(playerPosition, Point(playerPosition.x, playerPosition.y - 1));

		setPlayerPosition(playerPosition.x, playerPosition.y - 1);
	}
}


void World::movePlayerDown() {
	if (organisms[playerPosition.x][playerPosition.y + 1] != nullptr) {
		//organisms[playerPosition.x][playerPosition.y + 1]->interact();
	}
	else {
		move(playerPosition, Point(playerPosition.x, playerPosition.y + 1));

		setPlayerPosition(playerPosition.x, playerPosition.y + 1);
	}
}


void World::movePlayerLeft() {
	if (organisms[playerPosition.x - 1][playerPosition.y] != nullptr) {
		//organisms[playerPosition.x - 1][playerPosition.y]->interact();
	}
	else {
		move(playerPosition, Point(playerPosition.x - 1, playerPosition.y));
		// set player position

		setPlayerPosition(playerPosition.x - 1, playerPosition.y);
	}
}


void World::movePlayerRight() {
	if (organisms[playerPosition.x + 1][playerPosition.y] != nullptr) {
		//organisms[playerPosition.x + 1][playerPosition.y]->interact();
	}
	else {
		move(playerPosition, Point(playerPosition.x + 1, playerPosition.y));

		setPlayerPosition(playerPosition.x + 1, playerPosition.y);
	}
}


bool World::isEmpty(Point position) {
	return organisms[position.x][position.y] == nullptr;
}


Point World::getRandomNeighbour(const Point& position) const {
	int random = rand() % 4;

	switch (random) {
	case 0: {
		return Point(position.x, position.y - 1);
	}
	case 1: {
		return Point(position.x, position.y + 1);
	}
	case 2: {
		return Point(position.x - 1, position.y);
	}
	case 3: {
		return Point(position.x + 1, position.y);
	}
	default: {
		return Point(0, 0);
	}
	}
}


void World::printOrganismInfo(Point position) {
	// print organism info
	std::cout << "Organism info:" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Organism strength: " << organisms[position.x][position.y]->getStrength() << std::endl;
}


void World::printTurnSummary() {
	std::cout << std::endl;
	std::cout << "Turn actions summary:" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Human position: " << playerPosition.x << ", " << playerPosition.y << std::endl;

	// print organism info for human position
	if (organisms[playerPosition.x][playerPosition.y] != nullptr) {
		std::cout << "Organism info:" << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << std::endl;
		
		printOrganismInfo(Point (playerPosition.x, playerPosition.y));
	}
}


void World::printStatistics() {
	// TODO: implement

	std::cout << std::endl;
	std::cout << "World statistics:" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;
}


Point World::getPlayerPosition() const {
	return playerPosition;
}


void World::setPlayerPosition(int x, int y) {
	playerPosition.x = x;
	playerPosition.y = y;
}


void World::setPlayerPosition(Point& position) {
	playerPosition = position;
}

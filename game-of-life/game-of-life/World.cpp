#include "World.h"


World::World(int size) : isPlayerAlive{ true }, playerAction{ PlayerAction::NONE } {
	this->size = size;
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			organisms[i][j] = nullptr;
		}
	}
}


World::~World() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (organisms[i][j] != nullptr) {
				delete organisms[i][j];
			}
		}
	}
}


void World::drawWorld() {
	system("cls");

	drawHorizontalBorder();
	
	for (int i = 0; i < size; i++) {
		std::cout << "# ";

		for (int j = 0; j < size; j++) {
			if (organisms[j][i] != nullptr) {
				std::cout << organisms[j][i]->getSymbol() << " ";
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
	for (int i = 0; i < size + 2; i++) {
		std::cout << "# ";
	}

	std::cout << std::endl;
}


void World::takeTurn() {
	sortOrganismsList();

	for (int i = 0; i < organismsList.size(); i++) {
		if (organismsList[i] == nullptr) {
			organismsList.erase(organismsList.begin() + i);
			i--;
			continue;
		}
		
		organismsList[i]->action();
	}
}


void World::spawnOrganism(Organism* organism) {
	int x = rand() % size;
	int y = rand() % size;
	
	while (organisms[x][y] != nullptr) {
		x = rand() % size;
		y = rand() % size;
	}
	
	organisms[x][y] = organism;
	organisms[x][y]->setPosition(x, y);

	organismsList.push_back(organism);
}


void World::setOrganism(Organism* organism, Point position) {
	organisms[position.x][position.y] = organism;
	organisms[position.x][position.y]->setPosition(position);

	organismsList.push_back(organism);
}


void World::createHuman(Organism* human, Point position) {
	organisms[position.x][position.y] = human;
	
	organisms[position.x][position.y]->setPosition(position);
	setPlayerPosition(position);

	organismsList.push_back(human);
}


void World::move(Point position, Point destination) {
	if (organisms[destination.x][destination.y] != nullptr) {
		organisms[position.x][position.y]->collision(*organisms[destination.x][destination.y]);

		return;
	}

	if (isWithinBoardBoundaries(destination) == false) {
		return;
	}
	
	organisms[destination.x][destination.y] = organisms[position.x][position.y];
	organisms[position.x][position.y] = nullptr;
}


void World::remove(Point position) {
	for (int i = 0; i < organismsList.size(); i++) {
		if (organismsList[i]->getPosition() == position) {
			organismsList.erase(organismsList.begin() + i);
		}
	}
	
	if (organisms[position.x][position.y] != nullptr) {
		delete organisms[position.x][position.y];
		organisms[position.x][position.y] = nullptr;
	}
}


bool World::isEmpty(Point position) {
	return organisms[position.x][position.y] == nullptr;
}


bool World::isOccupied(Point position) {
	return organisms[position.x][position.y] != nullptr;
}


bool World::isWithinBoardBoundaries(Point position) {
	return position.x >= 0 and position.x < size and position.y >= 0 and position.y < size;
}


bool World::isWithinBoardBoundaries(int x, int y, int size) {
	return x >= 0 and x < size and y >= 0 and y < size;
}


bool World::hasFreeSpace(Point position) {
	if (isWithinBoardBoundaries(position.x, position.y - 1, size) and organisms[position.x][position.y - 1] == nullptr) {
		return true;
	}

	if (isWithinBoardBoundaries(position.x, position.y + 1, size) and organisms[position.x][position.y + 1] == nullptr) {
		return true;
	}

	if (isWithinBoardBoundaries(position.x - 1, position.y, size) and organisms[position.x - 1][position.y] == nullptr) {
		return true;
	}

	if (isWithinBoardBoundaries(position.x + 1, position.y, size) and organisms[position.x + 1][position.y] == nullptr) {
		return true;
	}

	return false;
}


Point World::getRandomNeighbour(const Point& position) const {
	int randomNumber = rand() % 4;

	switch (randomNumber) {
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


Point World::getRandomFreeSpaceAround(const Point& position) const {
	std::vector<Point> freeSpaces;

	int x = position.x;
	int y = position.y;

	if (isWithinBoardBoundaries(x, y - 1, size) and organisms[x][y - 1] == nullptr) {
		freeSpaces.push_back(Point(position.x, position.y - 1));
	}

	if (isWithinBoardBoundaries(position.x, position.y + 1, size) and organisms[position.x][position.y + 1] == nullptr) {
		freeSpaces.push_back(Point(position.x, position.y + 1));
	}

	if (isWithinBoardBoundaries(position.x - 1, position.y, size) and organisms[position.x - 1][position.y] == nullptr) {
		freeSpaces.push_back(Point(position.x - 1, position.y));
	}

	if (isWithinBoardBoundaries(position.x + 1, position.y, size) and organisms[position.x + 1][position.y] == nullptr) {
		freeSpaces.push_back(Point(position.x + 1, position.y));
	}

	if (freeSpaces.size() == 0) {
		return Point(-1, -1);
	}

	int randomNumber = rand() % freeSpaces.size();

	return freeSpaces[randomNumber];
}


void World::addTurnSummaryMessage(const std::string& message) {
	turnSummaryMessages.push_back(message);
}


void World::printTurnSummaryMessages() {
	int messagesToPrint = turnSummaryMessages.size() > 10 ? 10 : turnSummaryMessages.size();
	
	for (int i = 0; i < messagesToPrint; i++) {
		std::cout << turnSummaryMessages[i] << "\n";
	}

	turnSummaryMessages.clear();
}


void World::addToOrganismsList(Organism* organism) {
	organismsList.push_back(organism);
}


void World::sortOrganismsList() {
	std::sort(organismsList.begin(), organismsList.end(), &World::compareOrganismsByInitiativeAndAge);
}


void World::clearOrganisms() {
	organismsList.clear();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (organisms[i][j] != nullptr) {
				delete organisms[i][j];
				organisms[i][j] = nullptr;
			}
		}
	}
}


bool World::compareOrganismsByInitiativeAndAge(Organism* lhs, Organism* rhs) {
	if (lhs->getInitiative() == rhs->getInitiative()) {
		return lhs->getAge() > rhs->getAge();
	}

	return lhs->getInitiative() > rhs->getInitiative();
}


void World::printOrganismsInfo() {
	std::cout << "Organisms info:\n";
	std::cout << "----------------\n";

	int counter = 0;
	
	for (auto organism : organismsList) {
		organism->printShortInfo();
		std::cout << "\t";

		counter++;
		if (counter == 30) {
			break;
		}
	}
}


void World::printTurnSummary() {
	std::cout << "\n";
	std::cout << "Turn actions summary:\n";
	std::cout << "----------------\n";

	std::cout << "Human position: " << playerPosition << "\n";
	std::cout << "Total number of organisms: " << organismsList.size() << "\n";

	for (auto message : turnSummaryMessages) {
		std::cout << message << "\n";
	}
	turnSummaryMessages.clear();

	printOrganismsInfo();
}


void World::printStatistics() {
	std::cout << "\n";
	std::cout << "World statistics:\n";
	std::cout << "----------------\n\n";
}


Point World::getPlayerPosition() const {
	return playerPosition;
}


PlayerAction World::getPlayerAction() const {
	return playerAction;
}


bool World::getIsPlayerAlive() const {
	return isPlayerAlive;
}


Organism* World::getOrganismAt(Point position) const {
	if (!isWithinBoardBoundaries(position.x, position.y, size)) {
		return nullptr;
	}
	
	return organisms[position.x][position.y];
}


std::vector<Organism*> World::getOrganismsList() const {
	return organismsList;
}


Organism* World::getHuman() const {
	for (auto organism : organismsList) {
		if (organism->getSpecies() == Species::HUMAN) {
			return organism;
		}
	}

	return nullptr;
}


void World::setPlayerPosition(int x, int y) {
	playerPosition.x = x;
	playerPosition.y = y;
}


void World::setPlayerAction(PlayerAction playerAction) {
	this->playerAction = playerAction;
}


void World::setPlayerPosition(Point& position) {
	playerPosition = position;
}


void World::setIsPlayerAlive(bool isPlayerAlive) {
	this->isPlayerAlive = isPlayerAlive;
}

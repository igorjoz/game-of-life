#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


#include "Organism.h"
#include "Point.h"
#include "Resources.h"


int const WORLD_SIZE = 15;


class World
{
private:
	Organism* organisms[WORLD_SIZE][WORLD_SIZE];
	std::vector<Organism*> organismsList;
	std::vector<std::string> turnSummaryMessages;
	
	Point playerPosition;
	PlayerAction playerAction;

	bool isPlayerAlive;

public:
	World();
	
	~World();

	void drawWorld();
	void drawHorizontalBorder();

	void takeTurn();
	void spawnOrganism(Organism* organism);
	void setOrganism(Organism* organism, Point position);
	void createHuman(Organism* organism, Point position);
	void move(Point position, Point destination);
	void remove(Point position);

	bool isEmpty(Point position);
	bool isOccupied(Point position);
	bool isWithinBoardBoundaries(Point position);
	bool static isWithinBoardBoundaries(int x, int y);
	bool hasFreeSpace(Point position);

	static bool compareOrganismsByInitiativeAndAge(Organism* lhs, Organism* rhs);

	Point getRandomNeighbour(const Point& position) const;
	Point getRandomFreeSpaceAround(const Point& position) const;

	void addTurnSummaryMessage(const std::string& message);

	void addToOrganismsList(Organism* organism);
	void sortOrganismsList();

	void printOrganismsInfo();
	void printTurnSummary();
	void printTurnSummaryMessages();
	void printStatistics();

	Point getPlayerPosition() const;
	PlayerAction getPlayerAction() const;
	bool getIsPlayerAlive() const;
	Organism* getOrganismAt(Point position) const;

	void setPlayerPosition(int x, int y);
	void setPlayerPosition(Point& position);
	void setPlayerAction(PlayerAction playerAction);
	void setIsPlayerAlive(bool isPlayerAlive);
};


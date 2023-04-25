#pragma once


#include <iostream>
#include <vector>


#include "Organism.h"
#include "Point.h"


int const WORLD_SIZE = 10;


class World
{
private:
	Organism* organisms[WORLD_SIZE][WORLD_SIZE];
	std::vector<Organism*> organismsList;
	Point playerPosition;

public:
	World();
	~World();

	void drawWorld();
	void drawHorizontalBorder();

	void spawnOrganism(Organism* organism);
	void setOrganism(Organism* organism, Point position);
	void createHuman(Organism* organism, Point position);
	void move(Point position, Point destination);
	void remove(Point position);

	void movePlayerUp();
	void movePlayerDown();
	void movePlayerLeft();
	void movePlayerRight();

	bool isEmpty(Point position);
	bool isWithinBoardBoundaries(Point position);
	bool isWithinBoardBoundaries(int x, int y);

	Point getRandomNeighbour(const Point& position) const;

	void printOrganismInfo(Point position);
	void printTurnSummary();
	void printStatistics();

	Point getPlayerPosition() const;
	void setPlayerPosition(int x, int y);
	void setPlayerPosition(Point& position);
};


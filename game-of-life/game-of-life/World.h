#pragma once


#include <iostream>


#include "Organism.h"
#include "Point.h"


int const WORLD_SIZE = 10;


class World
{
private:
	Organism* organisms[WORLD_SIZE][WORLD_SIZE];

public:
	World();
	~World();

	void drawWorld();
	void takeTurn();

	void move(Point position, Point destination);
	void remove(Point position);

	bool isEmpty(Point position);

	Point getRandomNeighbour(const Point& position) const;
};


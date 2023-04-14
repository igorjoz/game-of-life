#pragma once


#include <iostream>


#include "Organism.h"


int const WORLD_SIZE = 80;


class World
{
private:
	Organism* organisms[WORLD_SIZE][WORLD_SIZE];

public:
	World();
	~World();

	void drawWorld();
	void takeTurn();
};


#pragma once


#include "Point.h"


class World;


class Organism
{
private:
	int strength;
	int initiative;
	int age;
	char symbol;
	Point position;
	World& world;

	
public:
	Organism(World& world);
	Organism(int strength, int initiative, char symbol, Point position, World& world);
	Organism(int strength, int initiative, int age, char symbol, Point position, World& world);
	virtual ~Organism();

	virtual void action() = 0;
	virtual bool collision(Organism* other) = 0;
	virtual void draw() = 0;

	int getStrength() const;
	int getInitiative() const;
	int getAge() const;
	char getSymbol() const;
	Point& getPosition();
};


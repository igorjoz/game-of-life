#pragma once


#include "Point.h"


class World;


class Organism
{
protected:
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
	Organism(int strength, int initiative, char symbol, World& world);

	virtual ~Organism();

	virtual void action() = 0;
	virtual bool collision(Organism& other) = 0;
	virtual void reproduce(const Point& position) = 0;
	virtual void draw() = 0;
	virtual void die() = 0;
	virtual void kill(Organism& other) = 0;
	virtual bool canKill(const Organism& other) const = 0;
	virtual bool canBeKilledBy(const Organism& other) const = 0;
	
	void printInfo();
	void printShortInfo();

	int getStrength() const;
	int getInitiative() const;
	int getAge() const;
	char getSymbol() const;
	Point& getPosition();
	int getX() const;
	int getY() const;

	void setPosition(int x, int y);
	void setPosition(Point& position);
};


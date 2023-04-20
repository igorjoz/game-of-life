#pragma once


#include "Organism.h"
#include "World.h"


class Animal : public Organism
{
public:
	Animal(int strength, int initiative, char symbol, const Point& position, World& world);
	virtual ~Animal();

	virtual void action() override;
	virtual bool collision(Organism& other) override;
	
protected:
	virtual void move(const Point& position);
	virtual void eat(Organism& other);
	virtual void reproduce(const Point& position);

	virtual bool canMoveTo(const Point& destination) const;
	virtual bool canEat(const Organism& other) const;
};


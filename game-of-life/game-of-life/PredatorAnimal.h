#pragma once


#include "Organism.h"
#include "Animal.h"


//class Animal;


class PredatorAnimal : public Animal
{
public:
	PredatorAnimal(int strength, int initiative, char symbol, const Point& position, World& world);
	virtual ~PredatorAnimal();

	virtual void action() override;
	virtual bool collision(Organism& other) override;
	virtual void draw() override;
	
protected:
	virtual void move(const Point& position);
	virtual void eat(Organism& other);
	virtual void reproduce(const Point& position);

	virtual bool canMoveTo(const Point& destination) const;
	virtual bool canEat(const Organism& other) const;
};


#pragma once


#include "Organism.h"
#include "Animal.h"


class PredatorAnimal : public Animal
{
public:
	PredatorAnimal(int strength, int initiative, char symbol, const Point& position, World& world);
	PredatorAnimal(int strength, int initiative, char symbol, World& world);

	virtual ~PredatorAnimal();

	virtual void action() override;
	virtual bool collision(Organism& other) override;
	
protected:
	virtual void reproduce(const Point& position);
};


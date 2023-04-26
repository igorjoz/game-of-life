#pragma once


#include "Organism.h"
#include "Animal.h"


class PreyAnimal : public Animal
{
public:
	PreyAnimal(int strength, int initiative, char symbol, const Point& position, World& world);
	PreyAnimal(int strength, int initiative, char symbol, World& world);

	virtual ~PreyAnimal();

	virtual void action() override;
	virtual bool collision(Organism& other) override;
};


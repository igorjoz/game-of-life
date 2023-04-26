#pragma once


#include "PreyAnimal.h"


class Tortoise : public PreyAnimal
{
private:
	void reproduce(const Point& position) override;
	bool collision(Organism& other) override;
	
public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 2;
	static const int INITIATIVE = 1;
	static const char SYMBOL = 'T';

	Tortoise(const Point& position, World& world);
	Tortoise(World& world);

	virtual ~Tortoise();

	virtual void action() override;
	virtual bool canBeKilledBy(const Organism& other) const override;
};


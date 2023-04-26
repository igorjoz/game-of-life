#pragma once


#include "PreyAnimal.h"


class Antelope : public PreyAnimal
{
private:
	void reproduce(const Point& position) override;
	bool collision(Organism& other) override;

public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 4;
	static const int INITIATIVE = 4;
	static const char SYMBOL = 'A';

	Antelope(const Point& position, World& world);
	Antelope(World& world);

	virtual ~Antelope();

	virtual void action() override;

	virtual void die() override;
};


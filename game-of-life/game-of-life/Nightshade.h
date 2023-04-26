#pragma once


#include "Plant.h"


class Nightshade : public Plant
{
private:
	void reproduce(const Point& position) override;

public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 99;
	static const char SYMBOL = 'N';

	Nightshade(const Point& position, World& world);
	Nightshade(World& world);

	virtual ~Nightshade();

	virtual bool collision(Organism& other) override;

	virtual bool canReproduceThisTurn() const override;
};

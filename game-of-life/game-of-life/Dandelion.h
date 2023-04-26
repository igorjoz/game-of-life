#pragma once


#include "Plant.h"


class Dandelion : public Plant
{
private:
	void reproduce(const Point& position) override;

public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 0;
	static const int INITIATIVE = 0;
	static const char SYMBOL = 'D';

	Dandelion(const Point& position, World& world);
	Dandelion(World& world);

	virtual ~Dandelion();

	virtual bool canReproduceThisTurn() const override;
};


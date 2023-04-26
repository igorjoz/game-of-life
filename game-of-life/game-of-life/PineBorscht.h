#pragma once


#include "Plant.h"


class PineBorscht : public Plant
{
public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 0;
	static const char SYMBOL = 'P';

	PineBorscht(const Point& position, World& world);
	PineBorscht(World& world);

	virtual ~PineBorscht();

	virtual bool canReproduceThisTurn() const override;
	virtual bool canKill(const Organism& other) const override;

	virtual bool collision(Organism& other) override;
	virtual void action() override;
};


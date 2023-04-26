#pragma once


#include "Organism.h"
#include "World.h"


class Plant : public Organism
{
public:
	static const int INITIATIVE = 0;

	Plant(char symbol, const Point& position, World& world);
	Plant(int strength, char symbol, const Point& position, World& world);
	Plant(int strength, char symbol, World& world);

	virtual ~Plant();

	virtual void action() override;
	virtual bool collision(Organism& other) override;
	virtual void draw() override;
	virtual void die() override;

	virtual void kill(Organism& other) override;
	virtual bool canKill(const Organism& other) const override;

	virtual bool hasFreeSpace() const;
	virtual bool canReproduceThisTurn() const;

protected:
	virtual void reproduce(const Point& position) override;
};


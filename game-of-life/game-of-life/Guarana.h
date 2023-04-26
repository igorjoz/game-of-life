#pragma once


#include "Plant.h"


class Guarana : public Plant
{
private:
	void reproduce(const Point& position) override;

public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 0;
	static const char SYMBOL = 'U';

	Guarana(const Point& position, World& world);
	Guarana(World& world);

	virtual ~Guarana();

	virtual bool collision(Organism& other) override;
};


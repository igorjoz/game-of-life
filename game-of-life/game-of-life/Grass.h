#pragma once


#include "Plant.h"


class Grass : public Plant
{
public:
	static const int INITIAL_QUANTITY = 3;

	static const int STRENGTH = 0;
	static const char SYMBOL = 'G';

	Grass(World& world);
	Grass(const Point& position, World& world);

	~Grass();

protected:
	void reproduce(const Point& position) override;
};


#pragma once


#include "PreyAnimal.h"


class Sheep : public PreyAnimal
{
private:
	void reproduce(const Point& position) override;
	
public:
	static const int INITIAL_QUANTITY = 4;

	static const int STRENGTH = 4;
	static const int INITIATIVE = 4;
	static const char SYMBOL = 'S';

	Sheep(const Point& position, World& world);
	Sheep(World& world);

	virtual ~Sheep();
};


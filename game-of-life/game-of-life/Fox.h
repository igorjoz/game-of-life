#pragma once


#include "PredatorAnimal.h"


class Fox : public PredatorAnimal
{
private:
	void reproduce(const Point& position) override;
	bool collision(Organism& other) override;
	
public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 3;
	static const int INITIATIVE = 7;
	static const char SYMBOL = 'F';

	Fox(const Point& position, World& world);
	Fox(World& world);

	virtual ~Fox();
};


#pragma once


#include "PredatorAnimal.h"


class Wolf : public PredatorAnimal
{
private:
	void reproduce(const Point& position) override;

public:
	static const int INITIAL_QUANTITY = 2;

	static const int STRENGTH = 9;
	static const int INITIATIVE = 5;
	static const char SYMBOL = 'W';
	
	Wolf(const Point& position, World& world);
	Wolf(World& world);
	
	virtual ~Wolf();
};


#pragma once


#include "PredatorAnimal.h"


int const WOLF_STRENGTH = 9;
int const WOLF_INITIATIVE = 5;
char const WOLF_SYMBOL = 'W';


class Wolf : public PredatorAnimal
{
private:
	/*void move(const Point& position) override;
	void eat(Organism& other) override;
	void reproduce(const Point& position) override;

	bool canMoveTo(const Point& destination) const override;
	bool canEat(const Organism& other) const override;*/

public:
	Wolf(const Point& position, World& world);
	Wolf(World& world);
	
	virtual ~Wolf();

	virtual void draw() override;
};


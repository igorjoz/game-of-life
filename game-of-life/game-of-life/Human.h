#pragma once


#include "PredatorAnimal.h"


class Human : public PredatorAnimal
{
public:
	Human(const Point& position, World& world);
	Human(int strength, int initiative, char symbol, const Point& position, World& world);
	virtual ~Human();
	virtual void action() override;
	virtual bool collision(Organism& other) override;
	virtual void draw() override;

private:
	void move(const Point& position) override;
	void eat(Organism& other) override;
	void reproduce(const Point& position) override;

	bool canMoveTo(const Point& destination) const override;
	bool canEat(const Organism& other) const override;
};


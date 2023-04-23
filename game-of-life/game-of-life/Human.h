#pragma once


#include "Animal.h"


class Human : public Animal
{
	public:
	Human(const Point& position, World& world);
	Human(int strength, int initiative, char symbol, const Point& position, World& world);
	virtual ~Human();
	virtual void action() override;
	virtual bool collision(Organism& other) override;
	virtual void draw() override;

	private:
		void move(const Point& position);
		void eat(Organism& other);
		void reproduce(const Point& position);

		bool canMoveTo(const Point& destination) const;
		bool canEat(const Organism& other) const;
};


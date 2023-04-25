#pragma once


#include "PredatorAnimal.h"


enum SpecialAbility {
	NO_SPECIAL_ABILITY,
	ABILITY_SUPER_STRENGTH,
	ABILITY_SUPER_SPEED,
	ABILITY_SUPER_IMMUNITY
};


class Human : public PredatorAnimal
{
private:
	int specialAbilityCooldown;

	void move(const Point& position) override;
	void eat(Organism& other) override;
	void reproduce(const Point& position) override;

	bool canMoveTo(const Point& destination) const override;
	bool canEat(const Organism& other) const override;
	
public:
	Human(const Point& position, World& world);
	
	virtual ~Human();
	
	virtual void action() override;
	virtual bool collision(Organism& other) override;
	virtual void draw() override;

	void activateSpecialAbility(SpecialAbility specialAbility);
};


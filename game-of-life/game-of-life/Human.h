#pragma once


#include "PredatorAnimal.h"
#include "Resources.h"


class Human : public Animal
{
private:
	int specialAbilityCooldown;
	PlayerAction playerAction;

	//void move(const Point& position) override;
	void eat(Organism& other) override;
	void reproduce(const Point& position) override;

	bool canMoveTo(const Point& destination) const override;
	bool canEat(const Organism& other) const override;
	
public:
	static const int STRENGTH = 5;
	static const int INITIATIVE = 4;
	static const char SYMBOL = 'H';
	
	Human(const Point& position, World& world);
	
	virtual ~Human();
	
	virtual void action() override;
	virtual bool collision(Organism& other) override;
	virtual void draw() override;
	virtual void die() override;

	void activateSpecialAbility(SpecialAbility specialAbility);

	PlayerAction getPlayerAction() const;
	void setPlayerAction(PlayerAction playerAction);
};


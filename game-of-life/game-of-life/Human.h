#pragma once


#include "PredatorAnimal.h"
#include "Resources.h"


class Human : public Animal
{
private:
	PlayerAction playerAction;

	void reproduce(const Point& position) override;
	
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

	PlayerAction getPlayerAction() const;
	void setPlayerAction(PlayerAction playerAction);
};

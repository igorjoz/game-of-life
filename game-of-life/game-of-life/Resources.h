#pragma once


enum SpecialAbility {
	NO_SPECIAL_ABILITY,
	ABILITY_SUPER_STRENGTH,
	ABILITY_SUPER_SPEED,
	ABILITY_SUPER_IMMUNITY
};


enum PlayerAction {
	NONE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	USE_SPECIAL_ABILITY
};


int const ARROW_UP = 72;
int const ARROW_DOWN = 80;
int const ARROW_LEFT = 75;
int const ARROW_RIGHT = 77;

int const ESC = 27;

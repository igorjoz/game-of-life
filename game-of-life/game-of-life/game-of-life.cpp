#include <iostream>


#include "GameController.h"


int main()
{
	srand(time(NULL));
	
	GameController gameController = GameController();
	
	gameController.runGame();
	
	return 0;
}

#include <iostream>


#include "GameController.h"


int main()
{
	srand(time(NULL));

	int size;

	std::cout << "Enter size of the board: ";
	std::cin >> size;
	
	GameController gameController = GameController(size);
	
	gameController.runGame();
	
	return 0;
}

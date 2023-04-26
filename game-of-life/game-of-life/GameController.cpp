#include "GameController.h"


GameController::GameController(int size) :
	world { new World(size) },
	playerInput{ ' ' },
	isRunning{ true },
	turn{ 0 },
	specialAbilityCooldown { -1 },
	isSpecialAbilityActive { false },
	size{ size } {
}


GameController::~GameController() {
	delete world;
}


void GameController::runGame() {
	printWelcomeMessage();

	spawnInitialOrganisms();

	while (isRunning and world->getIsPlayerAlive()) {
		world->drawWorld();
		world->printTurnSummary();

		bool willActivateSpecialAbility = rand() % 2;

		if (specialAbilityCooldown < 2 and willActivateSpecialAbility) {
			if (isSpecialAbilityActive) {

				getInputFromPlayer();
				handlePlayerInput();

				world->getHuman()->action();

				if (!isRunning or !world->getIsPlayerAlive()) {
					break;
				}

				world->drawWorld();
				world->printTurnSummary();

				//specialAbilityCooldown--;

				if (specialAbilityCooldown <= 0) {
					isSpecialAbilityActive = false;
					specialAbilityCooldown = 5;
				}
			}
		}
		
		getInputFromPlayer();
		handlePlayerInput();

		if (!isRunning or !world->getIsPlayerAlive()) {
			break;
		}

		if (playerInput == 'k' or playerInput == 'l') {
			continue;
		}

		takeTurn();
		specialAbilityCooldown--;
	}

	printStatisticsAndThanksForPlayingMessage();
}


void GameController::takeTurn() {
	world->takeTurn();
	
	turn++;
}


void GameController::spawnInitialOrganisms() {
	createHuman();

	spawnWolves();
	spawnFoxes();

	spawnSheep();
	spawnTortoises();
	spawnAntelopes();
	
	spawnGrass();
	spawnDandelions();
	spawnGuarana();
	spawnNightshade();
	spawnPineBorscht();
}


void GameController::createHuman() {
	Point humanPosition = Point(0, 0);
	Human* human = new Human(humanPosition, *world);
	world->createHuman(human, humanPosition);
}


void GameController::spawnWolves() {
	for (int i = 0; i < Wolf::INITIAL_QUANTITY; i++) {
		Wolf* wolf = new Wolf(*world);
		world->spawnOrganism(wolf);
	}
}


void GameController::spawnFoxes() {
	for (int i = 0; i < Fox::INITIAL_QUANTITY; i++) {
		Fox* fox = new Fox(*world);
		world->spawnOrganism(fox);
	}
}


void GameController::spawnSheep() {
	for (int i = 0; i < Sheep::INITIAL_QUANTITY; i++) {
		Sheep* sheep = new Sheep(*world);
		world->spawnOrganism(sheep);
	}
}


void GameController::spawnTortoises() {
	for (int i = 0; i < Tortoise::INITIAL_QUANTITY; i++) {
		Tortoise* tortoise = new Tortoise(*world);
		world->spawnOrganism(tortoise);
	}
}


void GameController::spawnAntelopes() {
	for (int i = 0; i < Antelope::INITIAL_QUANTITY; i++) {
		Antelope* antelope = new Antelope(*world);
		world->spawnOrganism(antelope);
	}
}


void GameController::spawnGrass() {
	for (int i = 0; i < Grass::INITIAL_QUANTITY; i++) {
		Grass* grass = new Grass(*world);
		world->spawnOrganism(grass);
	}
}


void GameController::spawnDandelions() {
	for (int i = 0; i < Dandelion::INITIAL_QUANTITY; i++) {
		Dandelion* dandelion = new Dandelion(*world);
		world->spawnOrganism(dandelion);
	}
}


void GameController::spawnGuarana() {
	for (int i = 0; i < Guarana::INITIAL_QUANTITY; i++) {
		Guarana* guarana = new Guarana(*world);
		world->spawnOrganism(guarana);
	}
}


void GameController::spawnNightshade() {
	for (int i = 0; i < Nightshade::INITIAL_QUANTITY; i++) {
		Nightshade* nightshade = new Nightshade(*world);
		world->spawnOrganism(nightshade);
	}
}


void GameController::spawnPineBorscht() {
	for (int i = 0; i < PineBorscht::INITIAL_QUANTITY; i++) {
		PineBorscht* pineBorscht = new PineBorscht(*world);
		world->spawnOrganism(pineBorscht);
	}
}


void GameController::getInputFromPlayer() {
	playerInput = _getch();
	std::cout << playerInput << std::endl;

	if (playerInput <= 0 or playerInput == 224) {
		playerInput = _getch();
	}
}


void GameController::handlePlayerInput() {	
	Human* human = dynamic_cast<Human*> (world->getOrganismAt(world->getPlayerPosition()));
	
	switch (playerInput) {
		case 'q':
		case ESC: {
			isRunning = false;
			break;
		}

		case 'w':
		case ARROW_UP: {
			world->setPlayerAction(PlayerAction::MOVE_UP);
			human->setPlayerAction(PlayerAction::MOVE_UP);
			break;
		}

		case 's':
		case ARROW_DOWN: {
			world->setPlayerAction(PlayerAction::MOVE_DOWN);
			human->setPlayerAction(PlayerAction::MOVE_DOWN);
			break;
		}

		case 'a':
		case ARROW_LEFT: {
			world->setPlayerAction(PlayerAction::MOVE_LEFT);
			human->setPlayerAction(PlayerAction::MOVE_LEFT);
			break;
		}

		case 'd':
		case ARROW_RIGHT: {
			world->setPlayerAction(PlayerAction::MOVE_RIGHT);
			human->setPlayerAction(PlayerAction::MOVE_RIGHT);
			break;
		}

		case 'e': {
			activateSpecialAbility();
			break;
		}

		case 'k': {
			saveToFile();
			break;
		}

		case 'l': {
			loadFromFile();
			break;
		}

		default: {
			break;
		}
	}
}


void GameController::printWelcomeMessage() {
		std::cout << "Welcome to the Game of Life!\n";
		std::cout << "Author: Igor Jozefowicz, 193257\n";
		std::cout << "----------------\n\n";

		std::cout << "Controls:\n";
		std::cout << "Press 'w' OR arrow up to move up\n";
		std::cout << "Press 's' OR arrow down to move down\n";
		std::cout << "Press 'a' OR arrow left to move left\n";
		std::cout << "Press 'd' OR arrow right to move right\n";
		std::cout << "Press 'e' to use special ability\n";
		std::cout << "Press 'k' to save the game\n";
		std::cout << "Press 'l' to load the game\n";
		std::cout << "Press 'q' OR ESC to quit\n\n";
		std::cout << "----------------\n\n";

		std::cout << "Press any key to start the game...\n";

		playerInput = _getch();
}


void GameController::printStatistics() {
	std::cout << "Statistics:\n";
	std::cout << "----------------\n";
	std::cout << "Turns: " << turn << "\n";
	std::cout << "----------------\n";
}


void GameController::printStatisticsAndThanksForPlayingMessage() {
	printStatistics();
	world->printStatistics();

	std::cout << "Thanks for playing!\n";
	std::cout << "Press any key to exit...\n";

	playerInput = _getch();
}


void GameController::activateSpecialAbility() {
	isSpecialAbilityActive = true;
	specialAbilityCooldown = SPECIAL_ABILITY_COOLDOWN;
}


void GameController::saveToFile() {
	std::ofstream file;
	file.open("save.txt");

	file << turn << "\n";
	file << size << " ";
	file << world->getOrganismsList().size() << "\n";

	file << specialAbilityCooldown << " ";

	file << world->getPlayerPosition().x << " ";
	file << world->getPlayerPosition().y << "\n";

	for (Organism* organism : world->getOrganismsList()) {
		file << organism->getPosition().x << " ";
		file << organism->getPosition().y << " ";
		
		file << organism->getStrength() << " ";
		file << organism->getInitiative() << " ";
		file << organism->getAge() << " ";
		
		file << organism->getSymbol() << " ";
		file << organism->getIsAnimal() << " ";
		file << organism->getSpecies() << "\n";
	}

	file.close();
}


void GameController::loadFromFile() {
	std::ifstream file;

	file.open("save.txt");

	if (!file.is_open()) {
		std::cout << "Error: could not open file\n";

		return;
	}

	world->clearOrganisms();


	int organismsQuantity;
	int worldSize;
	int playerX, playerY;

	int specialAbilityCooldown;

	int x, y;
	int strength, initiative, age;
	char symbol;
	bool isAnimal;
	int species;

	file >> turn;
	file >> worldSize;
	file >> organismsQuantity;

	file >> specialAbilityCooldown;

	file >> playerX >> playerY;

	world->setPlayerPosition(playerX, playerY);
	this->specialAbilityCooldown = specialAbilityCooldown;

	for (int i = 0; i < organismsQuantity; i++) {
		file >> x;
		file >> y;
		file >> strength;
		file >> initiative;
		file >> age;
		file >> symbol;
		file >> isAnimal;
		file >> species;

		Organism* organism = nullptr;

		if (species == Species::HUMAN) {
			organism = new Human(Point(x, y), *world);
		}
		else if (species == Species::WOLF) {
			organism = new Wolf(Point(x, y), *world);
		}
		else if (species == Species::FOX) {
			organism = new Fox(Point(x, y), *world);
		}
		else if (species == Species::SHEEP) {
			organism = new Sheep(Point(x, y), *world);
		}
		else if (species == Species::TORTOISE) {
			organism = new Tortoise(Point(x, y), *world);
		}
		else if (species == Species::ANTELOPE) {
			organism = new Antelope(Point(x, y), *world);
		}
		else if (species == Species::GRASS) {
			organism = new Grass(Point(x, y), *world);
		}
		else if (species == Species::DANDELION) {
			organism = new Dandelion(Point(x, y), *world);
		}
		else if (species == Species::GUARANA) {
			organism = new Guarana(Point(x, y), *world);
		}
		else if (species == Species::NIGHTSHADE) {
			organism = new Nightshade(Point(x, y), *world);
		}
		else if (species == Species::PINE_BORSCHT) {
			organism = new PineBorscht(Point(x, y), *world);
		}

		organism->setStrength(strength);
		organism->setAge(age);

		world->setOrganism(organism, Point(x, y));
	}

	file.close();
}

#pragma once

#include <stdlib.h>

#include "Trex.h"
#include "Display.h"

class GameManager
{
private:
	Trex trex;
	Display display;
	int i;
	int j;

public:
	GameManager() : i(0), j(6 + rand() % 5) {};
	void Init();
	bool Game();
};
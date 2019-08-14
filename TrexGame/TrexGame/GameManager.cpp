#include <vector>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#include "GameManager.h"
#include "Trex.h"
#include "Display.h"
#include "Obstacle.h"


void GameManager::Init()
{
	trex.Init();
	display.Init();
}

bool GameManager::Game()
{
	static std::vector<Obstacle> obstacles;

	if (_kbhit())
	{
		int c = _getch();
		if (c == ' ')
		{
			trex.Jump();
		}
	}

	trex.SetPos();

	if (i == j)
	{
		obstacles.push_back(Obstacle(1, 1 + rand() % 3));
		j = 6 + rand() % 5;
		i = 0;
	}
	else
	{
		i++;
	}

	if (obstacles.size() != 0)
	{
		if (obstacles[0].isOut())
		{
			obstacles.erase(obstacles.begin());
		}
	}

	for (int k = 0; k < obstacles.size(); k++)
	{
		obstacles[k].Move();
	}

	if (trex.isDead(obstacles))
	{
		return true;
	}

	system("cls");
	display.Draw(obstacles, trex);
	return false;
}
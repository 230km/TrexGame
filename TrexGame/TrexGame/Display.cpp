#include <windows.h>
#include <iostream>

#include "Display.h"
#include "Trex.h"


Display::Display()
{

}

void Display::Init()
{
	system("mode con cols=100 lines=20");
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = FALSE;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Display::SetCursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Display::Draw(std::vector<Obstacle> obstacles, Trex trex)
{
	DrawMap();
	DrawObstacle(obstacles);
	DrawTrex(trex);
}

void Display::DrawMap()
{
	SetCursor(0, 16);
	printf("''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''");
}

void Display::DrawTrex(Trex trex)
{
	SetCursor(trex.GetX(), trex.GetY());
	printf("@");
	SetCursor(trex.GetX(), trex.GetY() + 1);
	printf("@");
}

void Display::DrawObstacle(std::vector<Obstacle> obstacles)
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		for (int j = 0; j < obstacles[i].GetSize(); j++)
		{
			SetCursor(obstacles[i].GetX() + j, obstacles[i].GetY());
			if (obstacles[i].GetX() + j <= 99 && obstacles[i].GetX() + j >= 0)
			{
				printf("#");
			}
		}
	}
}
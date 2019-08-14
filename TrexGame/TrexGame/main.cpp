#include <iostream>
#include <windows.h>

#include "GameManager.h"

int main()
{
	GameManager gameManager;

	gameManager.Init();

	while (1)
	{
		if (gameManager.Game())
		{
			break;
		}
		Sleep(100);
	}

	return 0;
}
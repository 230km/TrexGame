
#include "Trex.h"

void Trex::Init()
{

}

void Trex::Jump()
{
	if (!isJumping)
	{
		isJumping = true;
	}
}

void Trex::SetPos()
{
	static int i = 0;
	static int originalX = x;
	static int originalY = y;

	if (isJumping)
	{
		switch (i)
		{
		case 0:
			i = 1;
			height = 1;
			y = originalY - height;
			break;
		case 1:
			i = 2;
			height = 2;
			y = originalY - height;
			break;
		case 2:
			i = 3;
			height = 3;
			y = originalY - height;
			break;
		case 3:
			i = 4;
			height = 2;
			y = originalY - height;
			break;
		case 4:
			i = 5;
			height = 1;
			y = originalY - height;
			break;
		case 5:
			i = 0;
			height = 0;
			y = originalY - height;
			isJumping = false;
			break;
		}
	}
}

int Trex::GetX()
{
	return x;
}

int Trex::GetY()
{
	return y;
}

bool Trex::isDead(std::vector<Obstacle> obstacles)
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		for (int j = 0; j < obstacles[i].GetSize(); j++)
		{
			if (x == obstacles[i].GetX() + j)
			{
				if (y + 1 == obstacles[i].GetY())
				{
					return true;
				}
			}
		}
	}
	return false;
}
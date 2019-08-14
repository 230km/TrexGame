#include "Obstacle.h"

bool Obstacle::isOut()
{
	if (x < -3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Obstacle::Move()
{
	x -= speed;
}

int Obstacle::GetX()
{
	return x;
}

int Obstacle::GetY()
{
	return y;
}

int Obstacle::GetSize()
{
	return size;
}
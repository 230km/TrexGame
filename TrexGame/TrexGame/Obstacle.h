#pragma once

class Obstacle
{
private:
	int x;
	int y;
	int speed;
	int size;

public:
	Obstacle(int _speed, int _size) : speed(_speed), x(99), y(15), size(_size) {};
	bool isOut();
	void Move();
	int GetX();
	int GetY();
	int GetSize();
};
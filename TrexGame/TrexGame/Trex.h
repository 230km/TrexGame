#pragma once

#include <vector>

#include "Obstacle.h"

class Trex
{
private:
	int x;
	int y;
	int height;
	bool isJumping;

public:
	Trex() : x(10), y(14), height(0), isJumping(false) {};
	void Init();
	void Jump();
	void SetPos();
	bool isDead(std::vector<Obstacle> obstacles);

	int GetX();
	int GetY();
};
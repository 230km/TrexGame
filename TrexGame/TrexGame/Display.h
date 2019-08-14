#pragma once

#include <vector>

#include "Trex.h"
#include "Obstacle.h"

class Display
{
private:
	void SetCursor(int x, int y);

public:
	void DrawMap();
	void DrawTrex(Trex trex);
	void DrawObstacle(std::vector<Obstacle> obstacles);
	Display();
	void Init();
	void Draw(std::vector<Obstacle> obstacles, Trex trex);
};
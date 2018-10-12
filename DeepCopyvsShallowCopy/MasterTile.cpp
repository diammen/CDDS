#include <string>
#include <iostream>
#include "raylib.h"
#include "Tile.h"
#include "MasterTile.h"

MasterTile::MasterTile()
{
	types = new Tile[3];
	grid = new int[40];
	rows = 5;
	cols = 5;
}

MasterTile::~MasterTile()
{
	delete[] types;
	delete[] grid;
}

void MasterTile::draw()
{
	int width = 64;
	int height = 64;
	int yCounter = 0;
	int xCounter = 0;

	for (int i = 0; i < 210; ++i)
	{
		if (xCounter == 15)
		{
			yCounter++;
			xCounter = 0;
		}
		if (grid[i] == 0)
			DrawTexture(types[0].Background, 0 + width * xCounter, 0 + height * yCounter, types[0].tint);
		if (grid[i] == 1)
			DrawTexture(types[1].Background, 0 + width * xCounter, 0 + height * yCounter, types[1].tint);
		if (grid[i] == 2)
			DrawTexture(types[2].Background, 0 + width * xCounter, 0 + height * yCounter, types[2].tint);
		xCounter++;
	}
}
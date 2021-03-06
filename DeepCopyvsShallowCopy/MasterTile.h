#pragma once

#include <string>
#include <iostream>
#include "raylib.h"
#include "Tile.h"
using std::string;

class MasterTile
{
public:
	Tile * types;
	int * grid;
	Rectangle * tilePos;
	int rows;
	int cols;

	MasterTile();
	~MasterTile();

	void draw();
};
#pragma once

#include <string>
#include <iostream>
#include "raylib.h"
using std::string;

class Tile
{
public:
	// variables
	Rectangle rec;
	Texture2D Background;
	Color tint;

	// constructors and destructors
	Tile(string imageFilename);
	Tile();
	~Tile();
};
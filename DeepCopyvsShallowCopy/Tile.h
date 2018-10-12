#pragma once

#include <string>
#include <iostream>
#include "raylib.h"
using std::string;

class Tile
{
public:
	// variables
	Texture2D Background;
	Color tint;

	// constructors and destructors
	Tile(string imageFilename);
	Tile();
	~Tile();
};
#include <string>
#include <iostream>
#include "raylib.h"
#include "Tile.h"
using std::string;

Tile::Tile()
{
	tint = WHITE;
}

Tile::Tile(string imageFilename)
{
	Background = LoadTexture(imageFilename.c_str());
	tint = WHITE;
}

Tile::~Tile()
{
	UnloadTexture(Background);
}
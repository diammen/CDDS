#pragma once
#include "sprite.h"
using std::string;

class button : public sprite
{
public:
	void draw(); // overrides base class draw
	bool checkForClick();

	button(const string *fileName, const Vector2 & position, const int cellCount)
	{
		spriteCells = new Texture2D[cellCount];
		for (int i = 0; i < cellCount; ++i)
		{
			spriteCells[i] = LoadTexture(fileName[i].c_str());
		}
		frameCount = cellCount;
		x = position.x;
		y = position.y;
	}
	~button()
	{
		for (int i = 0; i < frameCount; ++i)
		{
			UnloadTexture(spriteCells[i]);
		}
		delete[] spriteCells;
	}
};
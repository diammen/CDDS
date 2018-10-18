#include "raylib.h"
#include "button.h"
#include <iostream>
using std::string;

button::button(const string *fileName, const Vector2 & position, const int cellCount)
{
	spriteCells = new Texture2D[cellCount];
	for (int i = 0; i < cellCount; ++i)
	{
		spriteCells[i] = LoadTexture(fileName[i].c_str());
	}
	frameCount = cellCount;
	x = position.x;
	y = position.y;
	rec.x = x;
	rec.y = y;
}

button::~button()
{
	for (int i = 0; i < frameCount; ++i)
	{
		UnloadTexture(spriteCells[i]);
	}
	delete[] spriteCells;
}

void button::draw()
{
	if (checkForClick())
		DrawTextureEx(spriteCells[0], Vector2{ x,y }, 0, 1, WHITE);
	else
		DrawTextureEx(spriteCells[1], Vector2{ x,y }, 0, 1, WHITE);
}

bool button::checkForClick()
{
	if (CheckCollisionPointRec(GetMousePosition(), rec))
	{
		return true;
	}
	return false;
}
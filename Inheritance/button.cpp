#include "raylib.h"
#include "button.h"
#include <iostream>
using std::string;

void button::draw()
{
	if (checkForClick())
		DrawTextureEx(spriteCells[0], Vector2{ x,y }, 0, 1, WHITE);
	else
		DrawTextureEx(spriteCells[1], Vector2{ x,y }, 0, 1, WHITE);
}

bool button::checkForClick()
{
	Rectangle rec = { x, y, spriteCells[currentFrame].width, spriteCells[currentFrame].height };
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), rec))
		{
			return true;
		}
	}
	return false;
}
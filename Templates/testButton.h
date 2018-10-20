#pragma once
#include "gameObject.h"
class testButton
{
public:
	testButton(const string &fileName)
	{
		sprite = LoadTexture(fileName.c_str());
	}
	~testButton() {}

	void render();

	void setPos(Vector2 _pos)
	{
		pos = _pos;
	}
	void deInt()
	{
		UnloadTexture(sprite);
	}
	bool checkForClick()
	{
		Rectangle rec = { pos.x, pos.y, sprite.width, sprite.height };
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (CheckCollisionPointRec(GetMousePosition(), rec))
			{
				return true;
			}
		}
		return false;
	}

	bool enabled = true;
	Texture2D sprite;
	Vector2 pos;
};
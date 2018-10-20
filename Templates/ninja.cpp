#include "ninja.h"

void ninja::update(float delta)
{

}

void ninja::render()
{
	if (enabled)
		DrawTextureEx(sprite, pos, 0, 1, WHITE);
}

void ninja::setPos(Vector2 _pos)
{
	pos = _pos;
}

void ninja::deInt()
{
	UnloadTexture(sprite);
}

void ninja::move()
{
	if (IsKeyDown(KEY_W))
	{
		pos.y--;
	}
	if (IsKeyDown(KEY_S))
	{
		pos.y++;
	}
	if (IsKeyDown(KEY_A))
	{
		pos.x--;
	}
	if (IsKeyDown(KEY_D))
	{
		pos.x++;
	}
}

ninja::ninja(const string &fileName)
{
	sprite = LoadTexture(fileName.c_str());
}

ninja::~ninja()
{

}
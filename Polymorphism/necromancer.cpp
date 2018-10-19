#include "necromancer.h"

necromancer::necromancer(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
	speed = 2;
	position.x = rand() % 800;
	position.y = rand() % 450;
}

necromancer::~necromancer()
{
	UnloadTexture(mySprite);
}

bool necromancer::moveTo(Vector2 &dest)
{
	if (position.x != dest.x && position.y != dest.y)
	{
		position.x += (dest.x - position.x) * GetFrameTime() * speed;
		position.y += (dest.y - position.y) * GetFrameTime() * speed;
	}
	else
	{
		return true;
	}
}
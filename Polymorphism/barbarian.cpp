#include "barbarian.h"
#include <math.h>

barbarian::barbarian(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
	speed = 3;
}

bool barbarian::moveTo(Vector2 &dest)
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

barbarian::barbarian()
{
}


barbarian::~barbarian()
{
}
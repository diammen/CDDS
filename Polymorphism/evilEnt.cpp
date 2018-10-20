#include "evilEnt.h"

evilEnt::evilEnt(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
	speed = 100;
	position.x = rand() % 800;
	position.y = rand() % 450;
}

evilEnt::~evilEnt()
{
	UnloadTexture(mySprite);
}

bool evilEnt::moveTo(Vector2 &dest)
{
	if (position.x != dest.x && position.y != dest.y)
	{
		float x = dest.x - position.x;
		float y = dest.y - position.y;
		position.x += (dest.x - position.x) / sqrt(x * x + y * y) * GetFrameTime() * speed;
		position.y += (dest.y - position.y) / sqrt(x * x + y * y) * GetFrameTime() * speed;
	}
	else
	{
		return true;
	}
}
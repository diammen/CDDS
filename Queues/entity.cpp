#include "entity.h"


entity::entity(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
	speed = 100;
	position.x = GetMousePosition().x;
	position.y = GetMousePosition().y;
}

entity::entity()
{

}


entity::~entity()
{

}

bool entity::moveTo(Vector2 &dest)
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
	return false;
}

void entity::draw()
{
	DrawTextureEx(mySprite, position, 0, 1, WHITE);
}
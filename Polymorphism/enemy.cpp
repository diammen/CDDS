#include "enemy.h"



enemy::enemy(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

enemy::enemy()
{

}

enemy::~enemy()
{
	UnloadTexture(mySprite);
}

bool enemy::moveTo(Vector2 &dest)
{
	return false;
}

void enemy::draw()
{
	DrawTextureEx(mySprite, position, 0, 1, WHITE);
}
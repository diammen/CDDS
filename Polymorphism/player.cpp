#include "player.h"

player::player()
{

}

player::player(string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

player::~player()
{
	UnloadTexture(mySprite);
}

bool player::moveTo(Vector2 &dest)
{
	return false;
}

void player::draw()
{
	DrawTextureEx(mySprite, position, 0, 1, WHITE);
	//DrawTexturePro(mySprite, Rectangle{ 0,0, 32, 32 }, Rectangle{ position.x, position.y, 32, 32 }, Vector2{ 8,14 }, 0, WHITE);
}
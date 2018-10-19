#include "wizard.h"

wizard::wizard(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
	speed = 3;
}

bool wizard::moveTo(Vector2 &dest)
{
	if (position.x != dest.x && position.y != dest.y)
	{
		position = dest;
		return true;
	}
	return false;
}

wizard::wizard()
{

}

wizard::~wizard()
{
	UnloadTexture(mySprite);
}
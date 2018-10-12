#include "raylib.h"
#include "meep.h"

meep::meep()
{
	enabled = true;
	isPlayer = false;
	position = { 0,0 };
}
meep::meep(bool _enabled)
{

	texture = LoadTexture("spikeball.png");
	dTexture = new Texture2D(texture);
	enabled = _enabled;
	position = { 0,0 };
}

meep::meep(bool _enabled, char * fileName, bool _isPlayer)
{
	texture = LoadTexture(fileName);
	dTexture = new Texture2D(texture);
	enabled = _enabled;
	isPlayer = _enabled;
	position = { 0,0 };
}

void meep::update()
{
	if (!isPlayer) { return; };
}

void meep::refresh()
{
	if (enabled)
	{
		DrawTexture(*dTexture, 100, 100, WHITE);
	}
}

meep::~meep()
{
	UnloadTexture(texture);
	delete dTexture;
}
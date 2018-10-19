#include "raylib.h"
#include "sprite.h"
#include <iostream>
using std::string;

sprite::sprite()
{

}

sprite::sprite(const string *fileName, const int cellCount, const float _frameRate)
{
	spriteCells = new Texture2D[cellCount];
	for (int i = 0; i < cellCount; ++i)
	{
		spriteCells[i] = LoadTexture(fileName[i].c_str());
	}
	frameCount = cellCount;
	frameRate = _frameRate;
	x = 100;
	y = 100;
}

sprite::~sprite()
{
	for (int i = 0; i < frameCount; ++i)
	{
		UnloadTexture(spriteCells[i]);
	}
	delete[] spriteCells;
}

void sprite::draw()
{
	timer++;

	if (timer >= GetFPS() / frameRate)
	{
		timer = 0;
		currentFrame++;

		if (currentFrame > frameCount - 1) currentFrame = 0;
	}
	DrawTextureEx(spriteCells[currentFrame], Vector2{ x, y }, 0, 1, WHITE);
}
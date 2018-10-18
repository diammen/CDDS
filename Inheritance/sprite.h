#pragma once
#include "raylib.h"
#include <iostream>
#include <string>
using std::string;

class sprite : public Vector2
{
public:
	Texture2D * spriteCells;
	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;
	int currentFrame = 0;

	float timer = 0;

	void draw();

	sprite(const string *fileName, const int cellCount, const float _frameRate);
	sprite();
	~sprite();
};
#pragma once
#include "sprite.h"
#include "raylib.h"
#include <iostream>
#include <string>
using std::string;

class button : public sprite
{
public:
	Rectangle rec;
	void draw(); // overrides base class draw
	bool checkForClick();

	button(const string *fileName, const Vector2 & position, const int cellCount);
	button();
	~button();
};
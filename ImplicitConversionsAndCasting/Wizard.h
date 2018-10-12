#pragma once
#include <iostream>
#include "raylib.h"
using std::string;
class Wizard
{
public:
	Wizard();
	~Wizard();

	string name;
	int hp = 5;
	int mana = 50;
	bool enabled = true;
	int gold;

	Texture2D sprite;
	Color tint;
	Vector2 position;

	void draw();
};
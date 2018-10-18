#pragma once
#include <iostream>
#include "raylib.h"
using std::string;
class Barbarian
{
public:
	Barbarian();
	~Barbarian();

	string name;
	int hp = 5;
	int mana = 20;
	bool enabled = true;
	int gold;

	Texture2D sprite;
	Color tint;
	Vector2 position;

	void draw();
};
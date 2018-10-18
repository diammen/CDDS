#pragma once
#include <iostream>
#include "raylib.h"
using std::string;
class Player
{
public:
	Player();
	~Player();

	string name;
	int hp = 5;
	int mana = 20;
	int damage = 5;
	bool enabled = true;
	int gold;

	Texture2D sprite;
	Color tint;
	Vector2 position;

	void draw();
	void attack();
};

struct bullet
{
	Vector2 direction;
	bool enabled = false;
};
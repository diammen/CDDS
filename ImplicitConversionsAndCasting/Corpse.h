#pragma once
#include <iostream>
#include <raylib.h>
#include "Wizard.h"
#include "Barbarian.h"
using std::string;
class Corpse
{
public:
	Corpse(Wizard ent);
	Corpse(Barbarian ent);
	Corpse();
	~Corpse();

	string name;
	int mana = 50;
	bool enabled = false;
	int gold;

	Texture2D sprite;
	Color tint;
	Vector2 position;

	void draw();
};
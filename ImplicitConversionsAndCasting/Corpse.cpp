#include "raylib.h"
#include "Corpse.h"
#include <string>
using std::string;

void Corpse::draw()
{
	if (enabled)
		DrawTextureEx(sprite, position, 0, 1, tint);
}

Corpse::Corpse()
{
	string temp = "Wizard";
	name = temp;
	gold = 0;
	sprite = LoadTexture("zombie_idle_anim_f0.png");
	position = { 0,0 };
}

Corpse::Corpse(Wizard ent)
{
	name = ent.name;
	mana = ent.mana;
	gold = ent.gold;
	position = ent.position;
	sprite = ent.sprite;
	tint = RED;
}

Corpse::~Corpse()
{
	//UnloadTexture(sprite);
}
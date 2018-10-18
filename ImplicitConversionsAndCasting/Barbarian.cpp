#include "raylib.h"
#include "Barbarian.h"
#include <string>
using std::string;

void Barbarian::draw()
{
	if (enabled)
		DrawTextureEx(sprite, position, 0, 1, tint);
}

Barbarian::Barbarian()
{
	string temp = "Barbarian";
	name = temp;
	gold = 10;
	tint = WHITE;
	sprite = LoadTexture("zombie_idle_anim_f0.png");
	position = { 200,100 };
}

Barbarian::~Barbarian()
{
	//UnloadTexture(sprite);
}
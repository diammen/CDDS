#include "raylib.h"
#include "Wizard.h"
#include <string>
using std::string;

void Wizard::draw()
{
	if (enabled)
		DrawTextureEx(sprite, position, 0, 1, tint);
}

Wizard::Wizard()
{
	string temp = "Wizard";
	name = temp;
	gold = 0;
	tint = WHITE;
	sprite = LoadTexture("wizzard_f_idle_anim_f0.png");
	position = { 100,100 };
}

Wizard::~Wizard()
{
	//UnloadTexture(sprite);
}
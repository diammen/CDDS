#include "raylib.h"
#include "Player.h"
#include <iostream>
using std::string;

void Player::draw()
{
	if (enabled)
		DrawTextureEx(sprite, position, 0, 1, tint);
}

void Player::attack()
{
	Vector2 pos = GetMousePosition();
}

Player::Player()
{
	string temp = "Player";
	name = temp;
	gold = 0;
	tint = WHITE;
	sprite = LoadTexture("elf_f_hit_anim_f0.png");
	position = { 50,100 };
}


Player::~Player()
{
}

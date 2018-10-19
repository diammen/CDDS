#pragma once
#include "raylib.h"
#include <iostream>
using std::string;

class player
{
public:
	player(string &fileName);
	player();
	~player();

	Vector2 position = { 100,100 };
	float speed = 0;
	Texture2D mySprite;

	bool moveTo(Vector2 &dest);

	void draw();
};
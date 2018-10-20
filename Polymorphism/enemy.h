#pragma once
#include "raylib.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::vector;
class enemy
{
public:
	enemy(const string &fileName);
	enemy();
	~enemy();

	Vector2 position = { 100, 100 };
	float speed = 0;
	Texture2D mySprite;

	virtual bool moveTo(Vector2 &dest);

	void draw();
};

vector<enemy> updateVector(enemy *  enemies, int enemyCount);
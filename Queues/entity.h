#pragma once
#include "raylib.h"
#include "tVector.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::string;
using std::vector;

class entity
{
public:
	entity(const string &fileName);
	entity();
	~entity();

	tVector<entity> bullets;
	Vector2 position;
	float speed;
	bool enabled;
	Texture2D mySprite;

	bool moveTo(Vector2 &dest);

	void draw();
};
#pragma once
#include "gameObject.h"

class ninja
{
public:
	ninja(const string &fileName);
	~ninja();


	void update(float delta);
	void render();
	void setPos(Vector2 _pos);
	void deInt();
	void move();

	bool enabled = true;
	Texture2D sprite;
	Vector2 pos;
};
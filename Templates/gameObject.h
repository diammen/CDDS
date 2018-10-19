#pragma once
#include "raylib.h"
#include <iostream>
using std::string;

template<typename T>
class gameObject
{
public:
	bool enabled;
	T * object;

	void update(float delta)
	{

	}

	void render()
	{

	}

	void setPos(Vector2 pos)
	{
		
	}
};
#pragma once
#include "raylib.h"
#include <iostream>
using std::string;

template<typename T>
class gameObject
{
public:
	bool enabled = true;
	T * object;

	void update(float delta)
	{
		object->enabled = enabled;
		object->update(delta);
	}

	bool checkForClick()
	{
		if (object->checkForClick())
		{
			return true;
		}
		return false;
	}

	void render()
	{
		object->render();
	}

	void setPos(Vector2 _pos)
	{
		pos = _pos;
		object->setPos(pos);
	}

	void move()
	{
		object->move();
	}

	gameObject(T _object)
	{
		object = &_object;
	}
	gameObject() {}
	~gameObject()
	{
		object->deInt();
	}

	Vector2 pos;
	Texture2D sprite;
};
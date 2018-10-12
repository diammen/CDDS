#pragma once
#include "raylib.h"

class meep
{
public:

	// Vars
	bool enabled = true;
	bool isPlayer = true;
	Vector2 position;
	Texture2D texture;
	Texture2D* dTexture;

	// Constructors & Destructors
	meep();
	meep(bool _enabled);
	meep(bool _enabled, char * fileName, bool _isPlayer);
	~meep();
	
	// Misc Functions
	void refresh();
	void update();
};
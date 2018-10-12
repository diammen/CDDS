#pragma once
#include "Potion.h"
#include "raylib.h"
#include <cstring>
#include <string>
using std::string;

class MyHero
{
public:
	// variables
	string name;
	string special;
	int age;
	int hitPoints;
	int wealth;
	Texture2D texture;
	Texture2D* dTexture;

	// ctors & dtors
	MyHero(string fileName);
	~MyHero();

	// operator overload
	int operator += (Potion pot)
	{
		return hitPoints += pot.quality * pot.HPModifier;
	}

	// misc
	void draw(string fileName);
};
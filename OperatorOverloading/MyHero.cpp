#include "raylib.h"
#include "MyHero.h"
#include <string>
using std::string;

MyHero::MyHero(string fileName)
{
	name = "Guy";
	special = "Super Shotgun";
	age = 53;
	hitPoints = 100;
	wealth = 1000;
	texture = LoadTexture(fileName.c_str());
	dTexture = new Texture2D(texture);
}

void MyHero::draw(string fileName)
{
	texture = LoadTexture(fileName.c_str());
	dTexture = new Texture2D(texture);
	DrawTexture(*dTexture, 200, 200, WHITE);
}

MyHero::~MyHero()
{
	UnloadTexture(texture);
	delete dTexture;
}
#include "dialFace.h"

void clock::drawFace()
{
	DrawCircleLines(position.x, position.y, radius, BLACK);
	DrawLine(position.x, position.y, position.x + sin(seconds * 6 * PI / 180) * radius, position.y + -cos(seconds * 6 * PI / 180) * radius, RED);
}

void clock::tick()
{
	seconds++;
}

clock::dialFace()
{

}

clock::~dialFace()
{

}
#pragma once
#include "raylib.h"
#include <math.h>
static float currentAngle;
class dialFace
{
public:
	static Vector2 position;
	static float radius;
	static float seconds;
	static void drawFace();
	void tick();
	dialFace();
	~dialFace();
} typedef clock;
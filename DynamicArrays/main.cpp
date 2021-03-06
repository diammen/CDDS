/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "tVector.h"
#include "entity.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	
	//tVector<int> orig;
	//orig.push_back(1);
	//orig.push_back(2);
	//orig.push_back(3);

	//tVector<int> copy = orig;
	//orig.pop_back();
	//orig.pop_back();
	//orig.pop_back();

	//int values[3];
	//values[0] = copy[0];
	//values[1] = copy[1];
	//values[2] = copy[2];

	InitWindow(screenWidth, screenHeight, "Stacks");

	entity ball("ballshade_9.png");

	tVector<entity> ents;

	int count = 0;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		for (int i = 0; i < ents.size(); ++i)
		{
			Vector2 pos = GetMousePosition();
			ents[i].moveTo(pos);
		}
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			ents.push_back(ball);
			ents[ents.size()-1].position = GetMousePosition();
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);
		//temp.draw();
		for (int i = 0; i < ents.size(); ++i)
		{
			ents[i].draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------

	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
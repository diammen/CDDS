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

	InitWindow(screenWidth, screenHeight, "Dynamic Arrays");

	entity ball("ballshade_9.png");

	tVector<entity> ents;
	ents.push_back(ball);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);
		entity temp = ents[0];
		temp.draw();
		ents[0].draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------

	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
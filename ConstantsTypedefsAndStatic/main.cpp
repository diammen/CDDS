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
#include "dialFace.h"

float clock::radius = 250;
float clock::seconds = 0;
Vector2 clock::position = Vector2{ 250, 250 };

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 500;
	int screenHeight = 500;

	InitWindow(screenWidth, screenHeight, "Constants, Typedefs, and Static");

	clock clock;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		clock.tick();
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(WHITE);

		clock.drawFace();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------

	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
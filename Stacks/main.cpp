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
#include "tStack.h"
#include "tVector.h"
#include "entity.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	Vector2 pos;

	InitWindow(screenWidth, screenHeight, "Stacks");

	entity blueBall("blueball.png");
	entity redBall("redball.png");
	entity yellowball("yellowball.png");
	entity brownball("brownball.png");

	tStack<entity> ents;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyPressed(KEY_ONE))
		{
			ents.push(blueBall);
		}
		if (IsKeyPressed(KEY_TWO))
		{
			ents.push(redBall);
		}
		if (IsKeyPressed(KEY_THREE))
		{
			ents.push(yellowball);
		}
		if (IsKeyPressed(KEY_FOUR))
		{
			ents.push(brownball);
		}
		ents.top().moveTo(pos);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			pos = GetMousePosition();
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);
		//temp.draw();



		DrawTexture(ents.top().mySprite, 100, GetScreenHeight() - 50, WHITE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------

	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
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
#include "utils.h"
#include "gameObject.h"
#include "ninja.h"
#include "testButton.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	int test1 = min(2, 3);
	int test2 = max(5, 10);

	InitWindow(screenWidth, screenHeight, "Templates");

	Vector2 pos = { 100,100 };
	Vector2 pos1 = { 300,300 };
	ninja shinobi("ballshade_1.png");

	gameObject<ninja> myNinja(shinobi);
	myNinja.setPos(pos);

	string buttons[2] = { "bluebutton.png", "redbutton.png" };

	testButton button("bluebutton.png");
	gameObject<testButton> myButton(button);
	myButton.setPos(pos1);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		myNinja.update(GetFrameTime());
		myNinja.move();
		if (myButton.checkForClick())
		{
			myNinja.enabled = !myNinja.enabled;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);

		myNinja.render();
		myButton.render();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------

	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
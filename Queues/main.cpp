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
#include "tQueue.h"
#include "tStack.h"
#include "entity.h"
#include "baseCommand.h"
#include "moveTo.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Stacks");

	moveTo moveCommand;

	entity ball("blueball.png");

	tVector<entity> ents;
	ents.push_back(ball);

	tQueue<baseCommand*> commands;

	int count = 0;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			commands.push(new moveTo(GetMousePosition()));
		}
		if (!commands.empty())
		{
			if (commands.front()->doCommand(ents[ents.size() - 1]))
			{
				commands.pop();
			}
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
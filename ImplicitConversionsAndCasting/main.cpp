#include <raylib.h>
#include <string>
#include "Wizard.h"
#include "Corpse.h"
using std::string;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Wizard player;
	Corpse dead;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyPressed(KEY_LEFT))
			player.hp--;
		if (player.hp <= 0)
		{
			player.enabled = false;
			dead = player;
			dead.enabled = true;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
		if (player.enabled) { player.draw(); }
		if (dead.enabled) { dead.draw(); }
		DrawText(FormatText("HEALTH: %i", player.hp), 5, 5, 20, WHITE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
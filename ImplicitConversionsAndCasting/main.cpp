#include <raylib.h>
#include <string>
#include "Wizard.h"
#include "Corpse.h"
#include "Player.h"
using std::string;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Player player;
	Wizard wiz;
	Barbarian barb;
	Corpse dead;

	bullet playerBullet[5];

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyPressed(KEY_LEFT))
			wiz.hp--;
		if (IsKeyDown(KEY_W))
			player.position.y--;
		if (IsKeyDown(KEY_S))
			player.position.y++;
		if (IsKeyDown(KEY_D))
			player.position.x++;
		if (IsKeyDown(KEY_A))
			player.position.x--;
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			playerBullet[0].direction = player.position;
			playerBullet[0].enabled = true;
		}
		if (wiz.hp <= 0)
		{
			wiz.enabled = false;
			dead = wiz;
			dead.enabled = true;
		}
		for (int i = 0; i < 5; ++i)
		{
			if (playerBullet[i].enabled)
			{
				playerBullet[i].direction.x+= 3;
			}
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);

		if (player.enabled) { player.draw(); }
		if (wiz.enabled) { wiz.draw(); }
		if (dead.enabled) { dead.draw(); }
		DrawText(FormatText("HEALTH: %i", player.hp), 5, 5, 20, WHITE);
		DrawRectangle(playerBullet[0].direction.x, playerBullet[0].direction.y, 20, 5, WHITE);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
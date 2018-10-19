#include "raylib.h"
#include "player.h"
#include "wizard.h"
#include "barbarian.h"
#include "enemy.h"
#include "evilEnt.h"
#include "necromancer.h"
#include <iostream>
#include <string>
using std::string;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	srand(time(NULL));
	int screenWidth = 800;
	int screenHeight = 450;
	Vector2 mousePos = { 0,0 };

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	string sprites[15] = {};
	for (int i = 0; i < 15; ++i)
	{
		string temp = "ballshade_" + std::to_string(i + 1) + ".png";
		sprites[i] = temp;
	}
	string sprites2[4] = { "elf.png","wizard.png","necromancer.png","zombie.png" };
	string test = { "wizard.png" };
	string buttons[2] = { "bluebutton.png", "redbutton.png" };

	wizard player1(sprites2[1]);
	barbarian player2(sprites2[0]);

	enemy * enemies[2];
	enemies[0] = new evilEnt(sprites2[3]);
	enemies[1] = new necromancer(sprites2[2]);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsMouseButtonPressed(0))
		{
			mousePos = GetMousePosition();
			player1.moveTo(mousePos);
		}
		player2.moveTo(mousePos);
		enemies[0]->moveTo(player1.position);
		enemies[1]->moveTo(player1.position);
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		player1.draw();
		player2.draw();
		enemies[0]->draw();
		enemies[1]->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
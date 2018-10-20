#include "raylib.h"
#include "player.h"
#include "wizard.h"
#include "barbarian.h"
#include "enemy.h"
#include "evilEnt.h"
#include "necromancer.h"
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	srand(time(NULL));
	bool gameOver = true;
	int screenWidth = 800;
	int screenHeight = 450;
	int enemyCount = 0;
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
	vector<enemy> enemies2;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (!gameOver)
		{
			if (IsMouseButtonPressed(0))
			{
				mousePos = GetMousePosition();
				player1.moveTo(mousePos);
			}
			for (int i = 0; i < enemyCount; ++i)
			{
				enemies2[i].moveTo(player1.position);
			}
		}
		else
		{
			if (IsKeyPressed(KEY_ENTER))
			{
				enemies2 = updateVector(*enemies, enemyCount);
				gameOver = false;
			}
			if (IsKeyPressed(KEY_LEFT))
			{
				enemyCount--;
			}
			if (IsKeyPressed(KEY_RIGHT))
			{
				enemyCount++;
			}
			if (enemyCount < 0)
				enemyCount = 0;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		if (!gameOver)
		{
			player1.draw();
			for (int i = 0; i < enemyCount; ++i)
			{
				enemies2[i].draw();
			}
			//enemies[0]->draw();
			//enemies[1]->draw();
		}
		else
		{
			DrawText(FormatText("Enemy Count: %i", enemyCount), GetScreenWidth() / 2 - MeasureText("Enemy Count: %i", 20) / 2, GetScreenHeight() / 2, 20, BLACK);
			DrawText("Enter how many enemies will spawn.", 100, 100, 20, BLACK);
			DrawText("Left arrow key: less Right arrow key: more", 100, 150, 20, BLACK);
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
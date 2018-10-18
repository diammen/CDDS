#include "raylib.h"
#include "sprite.h"
#include "button.h"
#include <iostream>
#include <string>
using std::string;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	string sprites[15] = {};
	for (int i = 0; i < 15; ++i)
	{
		string temp = "ballshade_" + std::to_string(i+1) + ".png";
		sprites[i] = temp;
	}
	string buttons[2] = { "bluebutton.png", "redbutton.png"};

	sprite player(sprites, 15, 12.0f);
	button test(buttons, Vector2{ 300,300 }, 2);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_D))
		{
			player.x++;
		}
		if (IsKeyDown(KEY_A))
		{
			player.x--;
		}
		if (IsKeyDown(KEY_W))
		{
			player.y--;
		}
		if (IsKeyDown(KEY_S))
		{
			player.y++;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		player.draw();
		test.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
#include "raylib.h"
#include "MyHero.h"
#include "Potion.h"
#include <string>
using std::string;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	string fileName = "ouch1.png";

	InitWindow(screenWidth, screenHeight, "Operator Overloading");

	MyHero hero(fileName);

	Potion pot;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsKeyDown(KEY_LEFT))
		{
			hero.hitPoints--;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			hero += pot;
		}
		switch (hero.hitPoints)
		{
		case 100:
			fileName = "ouch1.png";
			break;
		case 75:
			fileName = "ouch2.png";
			break;
		case 50:
			fileName = "ouch3.png";
			break;
		case 25:
			fileName = "ouch4.png";
		case 0:
			fileName = "ouch5.png";
		}

		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(GRAY);

		DrawText(FormatText("Health: %i", hero.hitPoints), 5, 5, 20, WHITE);

		hero.draw(fileName);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------

	// Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	CloseWindow();
	//--------------------------------------------------------------------------------------
	return 0;
}
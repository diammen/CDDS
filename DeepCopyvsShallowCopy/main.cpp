#include "raylib.h"
#include "Tile.h"
#include "MasterTile.h"
#include <string>
using std::string;

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 960;
	int screenHeight = 960;
	int tileMode = 0;
	int mainGrid[] = { 
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 1
		0,1,1,0,0,1,1,1,1,1,0,0,0,0,0, // 2
		0,1,1,2,2,1,1,1,1,0,0,0,0,0,0, // 3
		0,2,2,2,2,2,1,0,0,0,0,0,0,0,0, // 4
		0,0,0,0,0,2,2,2,0,0,0,0,0,0,0, // 5
		0,0,0,0,0,2,2,2,2,2,0,0,0,0,0, // 6
		0,1,1,1,1,2,2,1,1,1,1,1,1,0,0, // 7
		0,1,1,1,0,0,0,1,1,1,1,0,0,0,0, // 8
		0,1,1,0,0,0,1,1,1,0,0,0,0,0,0, // 9
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 10
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 11
		0,0,0,0,0,0,0,0,0,1,1,1,1,1,0, // 12
		0,0,0,0,0,0,0,0,1,1,1,1,1,1,0, // 13 
		0,0,0,0,0,0,0,1,1,1,1,1,1,1,0, // 14
		0,0,0,0,0,0,1,1,1,1,1,1,1,1,0  // 15
	};
	Rectangle gridPos[225];

	InitWindow(screenWidth, screenHeight, "Deep Vs Shallow Copy");

	MasterTile masterTile;
	Tile grassTile("mappack\\PNG\\mapTile_022.png");
	Tile dirtTile("mappack\\PNG\\mapTile_087.png");
	Tile stoneTile("mappack\\PNG\\mapTile_027.png");

	masterTile.types[0] = grassTile;
	masterTile.types[1] = dirtTile;
	masterTile.types[2] = stoneTile;

	masterTile.grid = mainGrid;
	masterTile.tilePos = gridPos;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Vector2 mousePos = GetMousePosition();
			mousePos.x += 64;
			for (int i = 0; i < 225; ++i)
			{
				if (CheckCollisionPointRec(mousePos, masterTile.tilePos[i]))
				{
					masterTile.grid[i] = tileMode;
				}
			}
		}
		if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
		{
			Vector2 mousePos = GetMousePosition();
			mousePos.x += 64;
			for (int i = 0; i < 225; ++i)
			{
				if (CheckCollisionPointRec(mousePos, masterTile.tilePos[i]))
				{
					masterTile.grid[i] = tileMode;
				}
			}
		}

		if (IsKeyPressed(KEY_ONE)) // grass
			tileMode = 0;
		else if (IsKeyPressed(KEY_TWO)) // dirt
			tileMode = 1;
		else if (IsKeyPressed(KEY_THREE)) // stone
			tileMode = 2;
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		masterTile.draw();

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
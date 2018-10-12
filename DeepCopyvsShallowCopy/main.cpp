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
	int mainGrid[] = { 
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,
		0,1,1,2,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
		0,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0 };

	int static grid2[] = { 0 };

	InitWindow(screenWidth, screenHeight, "Operator Overloading");

	MasterTile masterTile;
	Tile grassTile("mappack\\PNG\\mapTile_022.png");
	Tile dirtTile("mappack\\PNG\\mapTile_087.png");
	Tile stoneTile("mappack\\PNG\\mapTile_027.png");

	masterTile.types[0] = grassTile;
	masterTile.types[1] = dirtTile;
	masterTile.types[2] = stoneTile;

	masterTile.grid = grid2;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------

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
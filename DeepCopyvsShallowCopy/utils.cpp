#include "raylib.h"
#include "Tile.h"
#include "MasterTile.h"
#include <string>
#include <fstream>
#include <iostream>
using std::string;

void readFile(string fileName)
{
	using namespace std;
	fstream file;

	file.open("test.txt", ios_base::in);

	if (!file.is_open())
	{
		CloseWindow();
	}

	file.clear();
	file.flush();
	file.close();
}
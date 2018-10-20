#include "enemy.h"



enemy::enemy(const string &fileName)
{
	mySprite = LoadTexture(fileName.c_str());
}

enemy::enemy()
{

}

enemy::~enemy()
{
	//UnloadTexture(mySprite);
}

bool enemy::moveTo(Vector2 &dest)
{
	return false;
}

void enemy::draw()
{
	DrawTextureEx(mySprite, position, 0, 1, WHITE);
}

vector<enemy> updateVector(enemy * enemies, int enemyCount)
{
	vector<enemy> newVec;
	for (int i = 0; i < enemyCount; ++i)
	{
		int random = rand() % 2;
		newVec.push_back(enemies[random]);
		newVec[i].position.x = rand() % 800;
		newVec[i].position.y = rand() % 450;
	}
	return newVec;
}
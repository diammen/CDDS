#pragma once
#include "enemy.h"

class necromancer : public enemy
{
public:
	necromancer(const string &fileName);
	~necromancer();

	bool moveTo(Vector2 &dest);
};


#pragma once
#include "enemy.h"
class evilEnt : public enemy
{
public:
	evilEnt(const string &fileName);
	~evilEnt();

	bool moveTo(Vector2 &dest);
};


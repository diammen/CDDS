#pragma once
#include "player.h"
class barbarian : public player
{
public:
	barbarian(const string &fileName);
	barbarian();
	~barbarian();

	bool moveTo(Vector2 &dest);
};
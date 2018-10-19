#pragma once
#include "player.h"

class wizard : public player
{
public:
	wizard(const string &fileName);
	wizard();
	~wizard();

	bool moveTo(Vector2 &dest);
};
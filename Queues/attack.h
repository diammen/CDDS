#pragma once
#include "baseCommand.h"

class attack : public baseCommand
{
public:
	attack();
	attack(const Vector2 _pos);

	Vector2 dest;

	bool doCommand(entity &ent);
};


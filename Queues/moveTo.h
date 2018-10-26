#pragma once
#include "baseCommand.h"

class moveTo : public baseCommand
{
public:
	moveTo();
	moveTo(Vector2 _dest);
	Vector2 dest;

	bool doCommand(entity &ent);
};
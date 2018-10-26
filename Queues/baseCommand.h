#pragma once
#include "entity.h"
#include <math.h>
class baseCommand
{
public:
	baseCommand();

	virtual bool doCommand(entity &ent);

};
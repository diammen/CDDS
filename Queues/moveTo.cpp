#include "moveTo.h"

moveTo::moveTo()
{

}

moveTo::moveTo(Vector2 _dest)
{
	dest = _dest;
}

bool moveTo::doCommand(entity &ent)
{
	if (!(abs(dest.x - ent.position.x) < 5) && !(abs(dest.y - ent.position.y) < 5))
	{
		Vector2 mousePos = dest;
		float x = mousePos.x - ent.position.x;
		float y = mousePos.y - ent.position.y;
		ent.position.x += (mousePos.x - ent.position.x) / sqrt(x * x + y * y) * GetFrameTime() * ent.speed;
		ent.position.y += (mousePos.y - ent.position.y) / sqrt(x * x + y * y) * GetFrameTime() * ent.speed;
	}
	else
	{
		return true;
	}
	return false;
}
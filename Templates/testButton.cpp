#include "testButton.h"

void testButton::render()
{
	if (enabled)
		DrawTextureEx(sprite, pos, 0, 1, WHITE);
}
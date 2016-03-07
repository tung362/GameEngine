#include "GameFunction.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstring>

using namespace sfw;

void DrawBox(Vector2 position, float height, float width)
{
	drawLine(position.x - width, position.y + height, position.x + width, position.y + height);
	drawLine(position.x + width, position.y + height, position.x + width, position.y - height);
	drawLine(position.x + width, position.y - height, position.x - width, position.y - height);
	drawLine(position.x - width, position.y - height, position.x - width, position.y + height);
}
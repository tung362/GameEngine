#include "GameFunction.h"
#include "sfwdraw.h"
#include <iostream>
#include <cstring>

using namespace sfw;

void DrawPlane(Vector2 position, Vector2 normal)
{
	Vector2 perp = normal.Perp();
	drawLine(position.x, position.y, position.x + normal.x * 100, position.y + normal.y * 100); //Normal
	drawLine(position.x, position.y, position.x + perp.x * 100, position.y + perp.y * 100); //Right (Infinite)
	drawLine(position.x, position.y, position.x - perp.x * 100, position.y - perp.y * 100); //Left (Infinite)
}
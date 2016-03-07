#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Circle::Circle()
{
	position = Vector2(0, 0);
	radius = 1;
}

Circle::Circle(Vector2 newPosition, float newRadius)
{
	position = newPosition;
	radius = newRadius;
}

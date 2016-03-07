#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Ray::Ray()
{
}

Ray::Ray(Vector2 newPosition, Vector2 newDirection, float newLength)
{
	position = newPosition;
	direction = newDirection;
	length = newLength;
}

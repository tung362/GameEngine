#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Ray::Ray()
{
}

Ray::Ray(Vector3 newPosition, Vector3 newDirection, float newLength)
{
	position = newPosition;
	direction = newDirection;
	length = newLength;
}

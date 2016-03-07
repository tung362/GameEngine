#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Plane::Plane()
{
}

Plane::Plane(Vector2 newPosition, Vector2 newNormal)
{
	position = newPosition;
	normal = newNormal;
}

#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Plane::Plane()
{
}

Plane::Plane(Vector3 newPosition, Vector3 newNormal)
{
	position = newPosition;
	normal = newNormal;
}

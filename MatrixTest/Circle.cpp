#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Circle::Circle()
{
	position = Vector3(0, 0, 0);
	radius = 1;
}

Circle::Circle(Vector3 newPosition, float newRadius)
{
	position = newPosition;
	radius = newRadius;
}

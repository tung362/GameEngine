#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

AABB::AABB()
{
}

Vector3 AABB::Min()
{
	return position - halfExtents;
}

Vector3 AABB::Max()
{
	return position + halfExtents;
}

#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

AABB::AABB()
{
	position = Vector2(0, 0);
	halfExtents = Vector2(1, 1);
}

AABB::AABB(Vector2 newPosition, Vector2 newHalfExtents)
{
	position = newPosition;
	halfExtents = newHalfExtents;
}

Vector2 AABB::Min()
{
	return position - halfExtents;
}

Vector2 AABB::Max()
{
	return position + halfExtents;
}
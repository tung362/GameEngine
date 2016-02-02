#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

AABB::AABB()
{
}

/*Vector3 AABB::Min(Vector3 *v, size_t n)
{
	Vector3 m = Vector3(FLT_MAX, FLT_MAX);
	for (int i = 0; i < n; ++i)
	{
		m = Vector3(fminf(m.x, v[i].x), fminf(m.y, v[i].y));
	}
	return m;
}

Vector3 AABB::Max(Vector3 *v, size_t n)
{
	Vector3 m = Vector3(FLT_MAX, FLT_MAX);
	for (int i = 0; i < n; ++i)
	{
		m = Vector3(fmaxf(m.x, v[i].x), fmaxf(m.y, v[i].y));
	}
	return m;
}*/

Vector3 AABB::Position()
{
	return Vector3();
}

Vector3 AABB::Dimension()
{
	return Vector3();
}

void AABB::Rotate(float a)
{
}

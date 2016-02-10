#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

bool CollisionTest(const AABB &a, const AABB &b)
{
	return false;
}

bool CollisionTest(const AABB &a, const Circle &b)
{
	return false;
}

bool CollisionTest(const AABB &a, const Plane &b)
{
	return false;
}

bool CollisionTest(const AABB &a, const Ray &b)
{
	return false;
}

bool CollisionTest(const Circle &a, const Circle &b)
{
	if (Distance(a.position, b.position) <= a.radius + b.radius) return true;
	else return false;
}

bool CollisionTest(const Circle &a, const Plane &b)
{
	return false;
}

bool CollisionTest(const Circle &a, const Ray &b)
{
	return false;
}

bool CollisionTest(const Ray &a, const Plane &b)
{
	return false;
}

Vector3 MTV_AABB(const AABB &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_AABB_Circle(const AABB &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_AABB_Plane(const AABB &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_AABB_Ray(const AABB &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_Circle_Circle(const Circle &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_Circle_Plane(const Circle &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_Circle_Ray(const Circle &a, const AABB &b)
{
	return Vector3();
}

Vector3 MTV_Ray_Plane(const Ray &a, const Plane &b)
{
	return Vector3();
}
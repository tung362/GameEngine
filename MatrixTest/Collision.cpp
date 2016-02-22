#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

CollisionData CollisionTest(const AABB &a, const AABB &b)
{
	return false;
}

CollisionData CollisionTest(const AABB &a, const Circle &b)
{
	return false;
}

CollisionData CollisionTest(const AABB &a, const Plane &b)
{
	return false;
}

CollisionData CollisionTest(const AABB &a, const Ray &b)
{
	return false;
}

CollisionData CollisionTest(const Circle &a, const Circle &b)
{
	if (Distance(a.position, b.position) <= a.radius + b.radius) return true;
	else return false;
}

CollisionData CollisionTest(const Circle &a, const Plane &b)
{
	return false;
}

CollisionData CollisionTest(const Circle &a, const Ray &b)
{
	return false;
}

CollisionData CollisionTest(const Ray &a, const Plane &b)
{
	return false;
}

//Reverse
CollisionData CollisionTest(const Circle &b, const AABB &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(const Plane &b, const AABB &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(const Ray &b, const AABB &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(const Plane &b, const Circle &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(const Ray &b, const Circle &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(const Plane &b, const Ray &a)
{
	return CollisionTest(a, b);
}
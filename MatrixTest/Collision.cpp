#include <iostream>
#include <cstring>
#include "TNL.h"


using std::cout;
using std::endl;

CollisionData CollisionTest(AABB &a, AABB &b)
{
	CollisionData temp;
	//Is colliding
	if(a.Max().x >= b.Min().x && b.Max().x >= a.Min().x &&
	   a.Max().y >= b.Min().y && b.Max().y >= a.Min().y) temp.isOverlap = true;
	else temp.isOverlap = false;

	//Penetration depth
	Vector2 pDR = a.Max() - b.Min();
	Vector2 pDL = b.Max() - a.Min();
	Vector2 pD = Vector2(fminf(pDR.x, pDL.x), fminf(pDR.y, pDL.y));
	temp.penetrationDepth = fminf(pD.x, pD.y);
	//cout << "Penetration: " << temp.penetrationDepth << endl;

	//Collision normal
	Vector2 handedness = Vector2(std::copysignf(1, pDR.x - pDL.x), std::copysignf(1, pDR.y - pDL.y));
	temp.collisionNormal = handedness * temp.penetrationDepth;
	//cout << "Normal: " << temp.collisionNormal.x << "," << temp.collisionNormal.y << endl;

	//Impulse
	//temp.impulseVector = temp.collisionNormal * temp.penetrationDepth;
	//cout << "Normal: " << temp.impulseVector.x << "," << temp.impulseVector.y << endl;
	return temp;
}

CollisionData CollisionTest(AABB &a, Circle &b)
{
	CollisionData temp;
	Vector2 closestPoint = Clamp(a.Min(), a.Max(), b.position);
	if(DotPro(b.position - closestPoint, b.position - closestPoint) <= b.radius*b.radius) temp.isOverlap = true;
	else temp.isOverlap = false;
	return temp;
}

CollisionData CollisionTest(AABB &a, Plane &b)
{
	CollisionData temp;
	if(fabsf(DotPro(b.normal, a.position - b.position)) <= Distance(a.position, Vector2(a.position.x - a.halfExtents.x, a.position.y)) * fabsf(DotPro(b.normal, Vector2(1, 0))) + Distance(a.position, Vector2(a.position.x, a.position.y + a.halfExtents.y)) * fabsf(DotPro(b.normal, Vector2(0, 1)))) temp.isOverlap = true;
	else temp.isOverlap = false;
	return temp;
}

CollisionData CollisionTest(AABB &a, Ray &b)
{
	CollisionData temp;
	Plane slabs[4];

	b.direction.x = (b.direction.x == 0) ? FLT_EPSILON : b.direction.x;
	b.direction.y = (b.direction.y == 0) ? FLT_EPSILON : b.direction.y;

	//Horizontal Parallel
	slabs[0].position = Vector2( a.Min().x  , a.position.y );
	slabs[0].normal = Vector2( -1, 0 );
	slabs[1].position = Vector2( a.position.x, a.Min().y );
	slabs[1].normal = Vector2( 0,-1 );
	//Vertical Parallel
	slabs[2].position = Vector2( a.Max().x  , a.position.y );
	slabs[2].normal = Vector2( 1, 0 );
	slabs[3].position = Vector2( a.position.x, a.Max().y );
	slabs[3].normal = Vector2( 0, 1 );

	float tmin = FLT_MAX;
	float tmax = -FLT_MAX;

	float distances[4];

	for (int i = 0; i < 4; ++i) distances[i] = DotPro(slabs[i].normal, b.position - slabs[i].position) / -(DotPro(slabs[i].normal, b.direction));

	tmin = fmaxf(fminf(distances[0], distances[2]), fminf(distances[1], distances[3]));
	tmax = fminf(fmaxf(distances[0], distances[2]), fmaxf(distances[1], distances[3]));

	if(tmin <= tmax && 0 <= tmin && tmin <= b.length) temp.isOverlap = true;
	else temp.isOverlap = false;

	return temp;
}

CollisionData CollisionTest(Circle &a, Circle &b)
{
	CollisionData temp;
	if (Distance(a.position, b.position) <= a.radius + b.radius) temp.isOverlap = true;
	else temp.isOverlap = false;
	return temp;
}

CollisionData CollisionTest(Circle &a, Plane &b)
{
	CollisionData temp;
	if (fabsf(DotPro(b.normal, a.position - b.position)) <= a.radius) temp.isOverlap = true;
	else temp.isOverlap = false;
	return temp;
}

CollisionData CollisionTest(Circle &a, Ray &b)
{
	CollisionData temp;
	Vector2 closestPoint = b.position + b.direction * Clamp(0, b.length, DotPro(a.position - b.position, b.direction));
	temp.isOverlap = DotPro((a.position - closestPoint), (a.position - closestPoint)) <= a.radius*a.radius;
	return temp;
}

CollisionData CollisionTest(Ray &a, Plane &b)
{
	CollisionData temp;
	if (0 <= DotPro(b.normal, a.position - b.position) / -(DotPro(b.normal, a.direction)) &&
	         DotPro(b.normal, a.position - b.position) / -(DotPro(b.normal, a.direction)) <= a.length) temp.isOverlap = true;
	else temp.isOverlap = false;
	return temp;
}

//Reverse
CollisionData CollisionTest(Circle &b, AABB &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(Plane &b, AABB &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(Ray &b, AABB &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(Plane &b, Circle &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(Ray &b, Circle &a)
{
	return CollisionTest(a, b);
}

CollisionData CollisionTest(Plane &b, Ray &a)
{
	return CollisionTest(a, b);
}
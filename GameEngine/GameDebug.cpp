#include <iostream>
#include <cstring>
#include "sfwdraw.h"
#include "MatrixTest\TNL.h"
#include "GameFunction.h"

using namespace sfw;
using std::cout;
using std::endl;

void CircleCircleTest(Circle &a, Circle &b, float speed)
{
	if (sfw::getKey('S')) a.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) a.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) a.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) a.position.x += sfw::getDeltaTime()  * speed;

	drawCircle(a.position.x, a.position.y, a.radius);
	drawCircle(b.position.x, b.position.y, b.radius);

	cout << CollisionTest(a, b).isOverlap << endl;
}

void BoxBoxTest(AABB &a, AABB &b, float speed)
{
	if (sfw::getKey('S')) a.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) a.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) a.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) a.position.x += sfw::getDeltaTime()  * speed;

	DrawBox(a.position, a.halfExtents.y, a.halfExtents.x);
	DrawBox(b.position, b.halfExtents.y, b.halfExtents.x);

	cout << CollisionTest(a, b).isOverlap << endl;
}

void BoxCircleTest(AABB &a, Circle &b, float speed)
{
	if (sfw::getKey('S')) b.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) b.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) b.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) b.position.x += sfw::getDeltaTime()  * speed;

	DrawBox(a.position, a.halfExtents.y, a.halfExtents.x);
	drawCircle(b.position.x, b.position.y, b.radius);

	//CollisionTest(a, b);
	cout << CollisionTest(a, b).isOverlap << endl;
}

void CirclePlaneTest(Circle &a, Plane &b, float speed)
{
	if (sfw::getKey('S')) a.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) a.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) a.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) a.position.x += sfw::getDeltaTime()  * speed;

	drawCircle(a.position.x, a.position.y, a.radius);
	DrawPlane(b.position, b.normal);

	cout << CollisionTest(a, b).isOverlap << endl;
}

void BoxPlaneTest(AABB &a, Plane &b, float speed)
{
	if (sfw::getKey('S')) a.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) a.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) a.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) a.position.x += sfw::getDeltaTime()  * speed;

	DrawBox(a.position, a.halfExtents.y, a.halfExtents.x);
	DrawPlane(b.position, b.normal);

	cout << CollisionTest(a, b).isOverlap << endl;
}

void RayPlaneTest(Ray &a, Plane &b, float speed)
{
	if (sfw::getKey('S')) a.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) a.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) a.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) a.position.x += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('P')) a.length += sfw::getDeltaTime() * 10;
	if (sfw::getKey('O')) a.length -= sfw::getDeltaTime() * 10;
	drawLine(a.position.x, a.position.y, a.position.x + a.direction.x * a.length, a.position.y + a.direction.y * a.length);
	DrawPlane(b.position, b.normal);

	cout << CollisionTest(a, b).isOverlap << endl;
}

void RayCircleTest(Ray &a, Circle &b, float speed)
{
	if (sfw::getKey('S')) b.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) b.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) b.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) b.position.x += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('P')) a.length += sfw::getDeltaTime() * 10;
	if (sfw::getKey('O')) a.length -= sfw::getDeltaTime() * 10;
	drawLine(a.position.x, a.position.y, a.position.x + a.direction.x * a.length, a.position.y + a.direction.y * a.length);
	drawCircle(b.position.x, b.position.y, b.radius);

	//CollisionTest(b, a);
	cout << CollisionTest(a, b).isOverlap << endl;
}

void RayCircleTest(Ray &a, AABB &b, float speed)
{
	if (sfw::getKey('S')) b.position.y -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('W')) b.position.y += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('A')) b.position.x -= sfw::getDeltaTime()  * speed;
	if (sfw::getKey('D')) b.position.x += sfw::getDeltaTime()  * speed;
	if (sfw::getKey('P')) a.length += sfw::getDeltaTime() * 10;
	if (sfw::getKey('O')) a.length -= sfw::getDeltaTime() * 10;
	drawLine(a.position.x, a.position.y, a.position.x + a.direction.x * a.length, a.position.y + a.direction.y * a.length);
	DrawBox(b.position, b.halfExtents.y, b.halfExtents.x);

	//CollisionTest(b, a);
	cout << CollisionTest(a, b).isOverlap << endl;
}
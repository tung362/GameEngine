#pragma once
#include "MatrixTest\TNL.h"

void DrawBox(Vector2 position, float height, float width);
void DrawPlane(Vector2 position, Vector2 normal);

//Debug
void CircleCircleTest(Circle &a, Circle &b, float speed);
void BoxBoxTest(AABB &a, AABB &b, float speed);
void BoxCircleTest(AABB &a, Circle &b, float speed);
void CirclePlaneTest(Circle &a, Plane &b, float speed);
void BoxPlaneTest(AABB &a, Plane &b, float speed);
void RayPlaneTest(Ray &a, Plane &b, float speed);
void RayCircleTest(Ray &a, Circle &b, float speed);
void RayCircleTest(Ray &a, AABB &b, float speed);
#include "TNL.h"
#include <assert.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <cmath>

using std::cout;
using std::endl;

bool ITest_Circle_Circle(const AABB &a, const AABB &b);

Matrix4x4 Matrix3ToMatrix4(Matrix3x3 m, float Z)
{
	Matrix4x4 newMatrix4x4(m.mm[0][0], m.mm[0][1], 0, m.mm[0][2],
						   m.mm[1][0], m.mm[1][1], 0, m.mm[1][2],
						            0,          0, 1,          Z,
						   m.mm[2][0], m.mm[2][1], 0, m.mm[2][2]);
	return newMatrix4x4;
}

Matrix4x4 Matrix3ToMatrix4(float *v, float Z)
{
	return{ v[0], v[1], 0, v[2],
			v[3], v[4], 0, v[5],
			0 ,   0 , 1,    0,
			v[6], v[7], Z, v[8]
	};
}

float Distance(Vector3 vec1, Vector3 vec2)
{
	Vector3 distance = vec1 - vec2;
	return distance.Magnitude();
}

float Distance(Vector2 vec1, Vector2 vec2)
{
	Vector2 distance = vec1 - vec2;
	return distance.Magnitude();
}

float DotPro(Vector3 vec, Vector3 otherVec)
{
	return vec.x*otherVec.x + vec.y*otherVec.y + vec.z*otherVec.z;
}

float DotPro(Vector2 vec, Vector2 otherVec)
{
	return vec.x*otherVec.x + vec.y*otherVec.y;
}

Vector3 ILerp(Vector3 start, Vector3 target, float percentage)
{
	return start * (1 - percentage) + target * percentage;
}

Vector2 ILerp(Vector2 start, Vector2 target, float percentage)
{
	return start * (1 - percentage) + target * percentage;
}

float ILerp(float start, float target, float percentage)
{
	return start * (1 - percentage) + target * percentage;
}

Vector3 CrossProduct(Vector3 a, Vector3 b)
{
	Vector3 crossProduct;
	crossProduct.x = a.y*b.z - a.z*b.y;
	crossProduct.y = a.z*b.x - a.x*b.z;
	crossProduct.z = a.x*b.y - a.y*b.x;
	return crossProduct;
}

Vector3 SurfaceNormal(Vector3 a, Vector3 b, Vector3 c)
{
	Vector3 side1 = b - a;
	Vector3 side2 = c - a;
	return CrossProduct(side1, side2);
}

Vector3 Reflect(Vector3 vec1, Vector3 normal)
{
	return -(2 * (DotPro(vec1, normal))) * normal + vec1;
}

Vector2 Reflect(Vector2 vec1, Vector2 normal)
{
	return -(2 * (DotPro(vec1, normal))) * normal + vec1;
}

float Clamp(float min, float max, float value)
{
	if (value < min) return min;
	else if (value > max) return max;
	else return value;
}

Vector3 Clamp(Vector3 min, Vector3 max, Vector3 value)
{
	int x = 0;
	int y = 0;
	int z = 0;

	if (value.x < min.x) x = min.x;
	else if (value.x > max.x) x = max.x;
	else x = value.x;

	if (value.y < min.y) y = min.y;
	else if (value.y > max.y) y = max.y;
	else y = value.y;

	if (value.z < min.z) z = min.z;
	else if (value.z > max.z) z = max.z;
	else z = value.z;

	return Vector3(x, y, z);
}

Vector2 Clamp(Vector2 min, Vector2 max, Vector2 value)
{
	int x = 0;
	int y = 0;

	if (value.x < min.x) x = min.x;
	else if (value.x > max.x) x = max.x;
	else x = value.x;

	if (value.y < min.y) y = min.y;
	else if (value.y > max.y) y = max.y;
	else y = value.y;

	return Vector2(x, y);
}

Vector2 Perp(Vector2 vec1)
{
	return Vector2(-vec1.y, vec1.x);
}

Vector3 Perp(Vector3 vec1)
{
	return Vector3(-vec1.y, vec1.x, vec1.z);
}
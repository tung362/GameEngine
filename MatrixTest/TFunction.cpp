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
	Matrix4x4 newMatrix4x4(m.mm[0][0], m.mm[1][0], 0, m.mm[2][0],
						   m.mm[0][1], m.mm[1][1], 0, m.mm[2][1],
									0,			0, 1,		   0,
						   m.mm[0][2], m.mm[1][2], Z, m.mm[2][2]);
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

float DotPro(Vector3 vec, Vector3 otherVec)
{
	return vec.x*otherVec.x + vec.y*otherVec.y + vec.z*otherVec.z;
}

Vector3 ILerp(Vector3 start, Vector3 target, float percentage)
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
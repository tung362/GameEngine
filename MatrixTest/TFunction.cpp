#include "TNL.h"
#include <assert.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <cmath>

using std::cout;
using std::endl;

/*Vector3 Min(Vector3 *v, size_t n)
{
	Vector3 m = Vector3(FLT_MAX, FLT_MAX);
	for (int i = 0; i < n; ++i)
	{
		m = Vector3(fminf(m.x, v[i].x), fminf(m.y, v[i].y));
	}
	return m;
}

Vector3 Max(Vector3 *v, size_t n)
{
	Vector3 m = Vector3(FLT_MAX, FLT_MAX);
	for (int i = 0; i < n; ++i)
	{
		m = Vector3(fmaxf(m.x, v[i].x), fmaxf(m.y, v[i].y));
	}
	return m;
}

AABB GenAABB(Vector3 pts, size_t dim)
{
	Vector3 n = Min(pts, n);
	Vector3 m = Max(pts, n);
	Vector3 p Vector3((m.x + m.x))
	Vector3 p
}

AABB rotate(const AABB &aabb, float a)
{
	float w = aabb.m_Dimension.x;
	float h = aabb.m_Dimension.y;

	float wp = fabs(h*sinf(a)) + fabs(w*cosf(a));
	float hp = fabs(w*sinf(a)) + fabs(h*cosf(a));

	return aabb.m_Position(wp, hp);
}*/

/*ConvexHull operator*(const Matrix3x3 &m, const ConvexHull &a)
{

}

CollisionData ITest_SAT(const ConvexHull &a, ConvexHull &b)
{
	std::vector<Vector3> axes;
	std::vector<float> pdepth;
	axes.reserve(a.verts.size() + b.verts.size());

	CollisionData cd = { INFINITY };

	for (int i = 0; i < a.verts.size(); ++i)
	{
		axes.push_back(perp(normal(a.verts[i] - a.verts[(i + 1) % a.verts.size()])));
	}

	for (int i = 0; i < b.verts.size(); ++i)
	{
		axes.push_back(perp(normal(b.verts[i] - b.verts[(i + 1) % b.verts.size()])));
	}

	for (int i = 0; i < axes.size(); ++i)
	{
		float amin = INFINITY, amax = -INFINITY;
		float bmin = INFINITY, bmax = -INFINITY;

		for (int i = 0; i < a.verts.size(); ++i)
		{
			float pp;
			amin = fminf(pp, amin);
			amax = fminf(pp, amax);
		}

		for (int i = 0; i < a.verts.size(); ++i)
		{
			float pp;
			amin = fminf(pp, amin);
			amax = fminf(pp, amax);
		}

		float pdepth = fminf(amax - bmin, bmax - amin);

		if (pdepth < cd.PenetrationDepth)
		{
			cd = { pdepth, axes[i] };
		}
	}
}*/

Matrix4x4 Matrix3ToMatrix4(Matrix3x3 m)
{
	Matrix4x4 newMatrix4x4(m.mm[0][0], m.mm[0][1], 0, m.mm[0][2],
						   m.mm[1][0], m.mm[1][1], 0, m.mm[1][2],
									0,			0, 1,		   0,
						   m.mm[2][0], m.mm[2][1], 0, m.mm[2][2]);
	return newMatrix4x4;
}

Matrix4x4 Matrix3ToMatrix4(float *v)
{
	return{ v[0], v[1], 0, v[2],
			v[3], v[4], 0, v[5],
			0 ,   0 , 1,    0,
			v[6], v[7], 0, v[8]
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
	return (target - start) * percentage + start;
}

float ILerp(float start, float target, float percentage)
{
	return (target - start) * percentage + start;
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
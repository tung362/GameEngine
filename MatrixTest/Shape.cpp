#include <iostream>
#include <cstring>
#include "TNL.h"

/*AABB operator*(Matrix3x3 &m, AABB &a)
{
	Vector2 omin = a.Min();
	Vector2 omax = a.Max();

	Vector2 rmin = m[2].GetXY();
	Vector2 rmax = m[2].GetXY();

	float p, q;

	for (unsigned j = 0; j < 2; ++j)
		for (unsigned i = 0; i < 2; ++i)
		{
			p = omin[i] * m[i][j];
			q = omax[i] * m[i][j];

			if (p < q) std::swap(p, q);
			rmin[j] += p;
			rmax[j] += q;
		}
	return{ (rmin + rmax) / 2, (rmin - rmax) / 2 };
}


Circle operator*(Matrix3x3 &m, Circle &a)
{
	Circle ret;
	ret.position = (m * Vector3(a.position.x, a.position.y, 1)).GetXY();

	Vector3 xrad(a.radius, 0, 0);
	Vector3 yrad(0, a.radius, 0);

	ret.radius = fmaxf((m*xrad).Magnitude(), (m*yrad).Magnitude());

	return ret;
}


Ray operator*(Matrix3x3 &m, Ray &a)
{
	Vector3 dir = Vector3(a.direction.x, a.direction.y, 0) * a.length;
	Vector3 pos(a.position.x, a.position.y, 1);

	return{ (m * pos).GetXY(), Perp((m * dir).GetXY()), dir.Magnitude() };
}

Plane operator*(Matrix3x3 &m, Plane &a)
{
	Vector3 nor(a.normal.x, a.normal.y, 0);
	Vector3 pos(a.position.x, a.position.y, 1);

	return{ (m * pos).GetXY(),(m * nor).GetXY() };
}

ConvexHull operator*(Matrix3x3 &m, ConvexHull &a)
{
	ConvexHull ret;
	for each(Vector2 p in ret.verts)
		ret.verts.push_back((m * Vector3(p.x, p.y, 1)).GetXY());

	return ret;
}*/
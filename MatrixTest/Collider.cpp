#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Collider::Collider() : shape(Collider::e_CIRCLE), circle({ { 0,0 },1 })
{ }

CollisionData EvaluateCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc)
{
	Transform t_lhs = at;
	Transform t_rhs = bt;
	Collider lhs = ac;
	Collider rhs = bc;

	if (lhs.shape > rhs.shape)
	{
		//std::swap(lhs, rhs);
		std::swap(t_lhs, t_rhs);
	}

	switch (lhs.shape | rhs.shape)
	{
	case Collider::e_CIRCLE:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.circle, t_rhs.GetGlobalTransform() * rhs.circle);

	case Collider::e_CIRCLE | Collider::e_AABB:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.circle, t_rhs.GetGlobalTransform() * rhs.aabb);

	case Collider::e_CIRCLE | Collider::e_RAY:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.circle, t_rhs.GetGlobalTransform() * rhs.ray);

	case Collider::e_CIRCLE | Collider::e_PLANE:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.circle, t_rhs.GetGlobalTransform() * rhs.plane);

	case Collider::e_AABB:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.aabb, t_rhs.GetGlobalTransform() * rhs.aabb);

	case Collider::e_AABB | Collider::e_RAY:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.aabb, t_rhs.GetGlobalTransform() * rhs.ray);

	case Collider::e_AABB | Collider::e_PLANE:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.aabb, t_rhs.GetGlobalTransform() * rhs.plane);

	case Collider::e_RAY | Collider::e_PLANE:
		return CollisionTest(t_lhs.GetGlobalTransform() * lhs.ray, t_rhs.GetGlobalTransform() * rhs.plane);
	}
}
#include <iostream>
#include <cstring>
#include "Transform.h"

using std::cout;
using std::endl;

Transform::Transform()
{
	parent = nullptr;
	Scale = Vector2(1, 1);
	position = Vector2(0, 0);
	angle = 0;
}

Transform::~Transform()
{
	auto t = children;
	for each(Transform *child in t) child->SetParent(parent);
	SetParent(nullptr);
}

Matrix3x3 Transform::GetGlobalTransform() const
{
	return
		Matrix3x3::Scale(Scale)
		* Matrix3x3::Rotate(angle)
		* Matrix3x3::Translate(position) 
	* (parent ? parent->GetGlobalTransform() 
		: Matrix3x3::Identity());
}

void Transform::SetParent(Transform * newParent)
{
	if (parent) parent->children.remove(this);

	if (newParent) newParent->children.push_front(this);

	parent = newParent;
}

void Transform::SetPosition(const Vector2 & newPosition)
{
	position = newPosition;
}

void Transform::SetScale(const Vector2 & newScale)
{
	Scale = newScale;
}

void Transform::SetAngle(float newAngle)
{
	angle = newAngle;
}

Vector2 Transform::GetPosition() const
{
	return position;
}

Vector2 Transform::GetScale() const
{
	return Scale;
}

float Transform::GetAngle() const
{
	return angle;
}

Vector2 Transform::GetRight() const
{
	return Vector2::SetAngle(angle);
}

Vector2 Transform::GetUp() const
{
	return Vector2::SetAngle(angle).Perp();
}

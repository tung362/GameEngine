#include <iostream>
#include <cstring>
#include <list>
#include "TNL.h"

using std::cout;
using std::endl;

Transform::Transform()
{
	parent = nullptr;
	Scale = Vector3(1, 1, 0);
	position = Vector3(0, 0, 0);
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

void Transform::SetPosition(const Vector3 & newPosition)
{
	position = newPosition;
}

void Transform::SetScale(const Vector3 & newScale)
{
	Scale = newScale;
}

void Transform::SetAngle(float newAngle)
{
	angle = newAngle;
}

Vector3 Transform::GetPosition() const
{
	return position;
}

Vector3 Transform::GetScale() const
{
	return Scale;
}

float Transform::GetAngle() const
{
	return angle;
}

Vector3 Transform::GetRight() const
{
	return Vector3::SetAngle(angle);
}

Vector3 Transform::GetUp() const
{
	return Vector3::SetAngle(angle).Normal();
}

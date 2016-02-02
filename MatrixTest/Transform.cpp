#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

/*Transform::Transform()
{
	parent = nullptr;
	Scale = Vector3(1, 1, 0);
	position = Vector3(0, 0, 0);
	angle = 0;
}

Transform::~Transform()
{
	//for each(Transform *child in )
}

void Transform::SetLocalTransform(Matrix3x3 &)
{
}

Matrix3x3 Transform::GetGlobalTransform() const
{
	(parent ? parent->GetGlobalTransform() :
		Matrix3x3::Identity())
		* Matrix3x3::Translate(position)
		* Matrix3x3::Scale(Scale)
		* Matrix3x3::Rotate(angle);
}

void Transform::SetParent(Transform * newParent)
{
	if(parent)
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

Vector3 Transform::GetPosition()
{
	return position;
}

Vector3 Transform::GetScale()
{
	return Scale;
}

float Transform::GetAngle()
{
	return angle;
}*/
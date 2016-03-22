#pragma once
#include "VMath.h"
#include <list>
#include "GCData.h"

class Transform : public GCData<Transform>
{
	Transform *parent;
	std::list<Transform*> children;
	Vector2 position;
	Vector2 Scale;
	float angle;

public:
	Transform();
	~Transform();
	Matrix3x3 GetGlobalTransform() const;

	void SetParent(Transform * newParent);
	void SetPosition(const Vector2 & newPosition);
	void SetScale(const Vector2 & newScale);
	void SetAngle(float newAngle);

	Vector2 GetPosition() const;
	Vector2 GetScale() const;
	float GetAngle() const;

	Vector2 GetRight() const;
	Vector2 GetUp() const;
};
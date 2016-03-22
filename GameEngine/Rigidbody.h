#pragma once
#include "VMath.h"
#include "GCData.h"

struct Rigidbody : public GCData<Rigidbody>
{
public:
	Vector2 gravity;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 force;
	Vector2 jerk;
	float gravityScaler;
	float mass;
	float drag;
	float angularVelocity;
	float ac;
	float torque;
	float angularDrag;
	Rigidbody();
	void AddForce(const Vector2 & newForce);
	void AddTorque(float newTorque);
	void Integrate(class Transform *, float dt);
};
#include "TNL.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

Rigidbody::Rigidbody()
{
	gravity = Vector2(0, -1); velocity = Vector2(0, 0); acceleration = Vector2(0, 0); force = Vector2(0, 0); jerk = Vector2(0, 0);
	gravityScaler = 1; mass = 1; drag = 0; angularVelocity = 0; angularAcceleration = 0; torque = 0; angularDrag = 0;
}

void Rigidbody::AddForce(const Vector2 & newForce)
{
	force = force + newForce;
}

void Rigidbody::AddTorque(float newTorque)
{
	torque = torque + newTorque;
}

void Rigidbody::Integrate(Transform * transform, float dt)
{
	jerk = force / mass - acceleration;
	acceleration = acceleration + jerk * dt; // acceleration = force/mass;
	velocity = velocity + acceleration * dt;
	velocity += gravity * gravityScaler;
	transform->SetPosition(transform->GetPosition() + velocity * dt);

	velocity = velocity - velocity * drag * dt;

	force = Vector2(0, 0);
}
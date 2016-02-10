#include "TNL.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

Rigidbody::Rigidbody()
{
	gravity = Vector3(0, -1, 0); velocity = Vector3(0, 0, 0); acceleration = Vector3(0, 0, 0); force = Vector3(0, 0, 0); jerk = Vector3(0, 0, 0);
	gravityScaler = 1; mass = 1; drag = 0; angularVelocity = 0; angularAcceleration = 0; torque = 0; angularDrag = 0;
}

void Rigidbody::AddForce(const Vector3 & newForce)
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

	force = Vector3(0, 0, 0);
}
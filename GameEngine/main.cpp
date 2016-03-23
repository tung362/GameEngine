/*#include <iostream>
#include <cstring>
#include "Window.h"
#include "sfwdraw.h"
#include "MatrixTest\TNL.h"
//#include "GameObject.h"
#include "GameFunction.h"
#include "Transform.h"
#include "Rigidbody.h"
//#include "Entity.h"
//#include "Vector2.h"
//#include "GLobalData.h"
#include <ctime>
#include <fstream>
#include <vector>

using namespace sfw;
using std::cout;
using std::endl;

int main()
{
	sfw::initContext();
	int  handle = sfw::loadTextureMap("./Textures/sword.png");

	float x = 400, y = 400;
	float angle = 0;
	float speed = 100;
	float angularSpeed = 15;
	float gravity = 0;

	Transform transform1;
	Transform transform2;
	Transform orbitalSpinner;
	transform1.SetPosition(Vector2(x, y));

	Rigidbody rigidbody1;
	rigidbody1.drag = 0.5f;
	rigidbody1.gravity = Vector2(0, -1);
	rigidbody1.gravityScaler = gravity;

	//Tests
	Circle acicle;
	acicle.position = Vector2(x, y);
	acicle.radius = 20;

	Circle acicle2;
	acicle2.position = Vector2(600, 500);
	acicle2.radius = 20;

	AABB abox;
	abox.position = Vector2(x, y);
	abox.halfExtents = Vector2(20, 20);

	AABB abox2;
	abox2.position = Vector2(600, 500);
	abox2.halfExtents = Vector2(20, 20);

	Plane aplane;
	aplane.position = Vector2(600, 200);
	aplane.normal = Vector2(0, 1);

	Ray aray;
	aray.position = Vector2(x, y);
	aray.direction = Vector2(0, 1).Normal();
	aray.length = 150;

	Matrix3x3 mat;

	while (sfw::stepContext())
	{
		if (sfw::getKey('S')) rigidbody1.AddForce(-transform1.GetUp() * speed);
		if (sfw::getKey('W')) rigidbody1.AddForce(transform1.GetUp() * speed);
		if (sfw::getKey('A')) rigidbody1.AddForce(-transform1.GetRight() * speed);
		if (sfw::getKey('D')) rigidbody1.AddForce(transform1.GetRight() * speed);
		if (sfw::getKey(' ')) rigidbody1.velocity = Vector2(rigidbody1.velocity.x, 100);
		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;

		transform1.SetAngle(angle);
		transform1.SetScale(Vector2(200, 200));

		rigidbody1.Integrate(&transform1, getDeltaTime());

		orbitalSpinner.SetParent(&transform1);
		orbitalSpinner.SetAngle(-sfw::getTime());

		transform2.SetParent(&orbitalSpinner);
		transform2.SetPosition(Vector2(.25f, .25f));
		transform2.SetScale(Vector2(.5f, .5f));

		Matrix4x4 m1 = Matrix3ToMatrix4(transform1.GetGlobalTransform(), 0.25);
		Matrix4x4 m2 = Matrix3ToMatrix4(transform2.GetGlobalTransform(), 0.1);

		sfw::drawTextureMatrix(handle, 0, WHITE, m1.m);
		sfw::drawTextureMatrix(handle, 0, MAGENTA, m2.m);

		//CircleCircleTest(acicle, acicle2 ,speed);
		//BoxBoxTest(abox, abox2, speed);
		//BoxCircleTest(abox2, acicle, speed);
		//CirclePlaneTest(acicle, aplane, speed);
		//BoxPlaneTest(abox, aplane, speed);
		//RayPlaneTest(aray, aplane, speed);
		//RayCircleTest(aray, acicle2, speed);
		//RayCircleTest(aray, abox, speed);
	}
	sfw::termContext();

	return 0;
}*/

/*int main()
{
	auto &window = Window::Instance();

	window.Init(600, 800, "Game Engine");

	while (window.Step())
	{

	}

	//window.Term();

	return 0;
}*/

#include "Window.h"
#include "Input.h"
#include "Time.h"
#include <iostream>
//#include "Factory.h"
//#include "DebugDraw.h"
//#include "RigidbodyDynamics.h"
#include "LifetimeSystem.h"

//#include "CollisionDetection.h"
//#include "DynamicResolution.h"

//#include "PlayerFlightSystem.h"
//#include "RenderSystem.h"
#include "Assets.h"

void main()
{
	auto &window = Window::instance();
	auto &input = Input::instance();
	auto &time = Time::instance();

	window.init();
	input.init();
	time.init();

	Asset::instance().loadTexture("Ship", "./Textures/sword.png");

	///Factory::makeBall({ 40,  40 },  {10,10},  400,  40)->rigidbody->addTorque(1000);
	///        Factory::makeBall({ 80,  200 },  { 100,0}, 120, 120);
	///auto e = Factory::makeBall({ 720, 200 }, { }, 60, 1);

	//Factory::makePlayer({ 0,0 });



	//DebugDraw debugDraw;
	//RigidbodyDynamics rigidbodies;
	LifetimeSystem lifetimes;
	//CollisionDetection collisioner;
	//DynamicResolution dynamic;
	//PlayerFlightSystem flightsystem;
	//RenderSystem render;

	while (window.step())
	{
		input.step();
		time.step();


		//flightsystem.step();


		//rigidbodies.step();
		lifetimes.step();

		//collisioner.step();
		//dynamic.step();
		//render.step();
		//debugDraw.step();
	}

	time.term();
	input.term();
	window.term();
}
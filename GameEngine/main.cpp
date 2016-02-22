#include "MatrixTest\TNL.h"
#include <iostream>
#include <cstring>
#include "sfwdraw.h"
//#include "GameObject.h"
//#include "GameFunction.h"
//#include "Entity.h"
//#include "Vector2.h"
//#include "GLobalData.h"
#include <ctime>
#include <fstream>
#include <vector>

using namespace sfw;
using std::cout;
using std::endl;

/*
int main()
{
sfw::initContext();
int  handle = sfw::loadTextureMap("./Textures/dino.png");

float x = 4, y = 5;
float angle = 0;
float speed = 100;
float angularSpeed = 15;
while (sfw::stepContext())
{
if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;
if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;

Matrix3x3 mat = Matrix3x3::Scale(Vector3(100, 100, 10)) * Matrix3x3::Rotate(angle) * Matrix3x3::Translate({ x,y,0 });
Matrix4x4 inMat = Matrix3ToMatrix4(mat);

sfw::drawTextureMatrix(handle, 0, WHITE, inMat.m);
}
sfw::termContext();

return 0;
}
*/


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
	transform1.SetPosition(Vector3(x, y, 0));

	Rigidbody rigidbody1;
	rigidbody1.drag = 0.5f;
	rigidbody1.gravity = Vector3(0, -1, 0);
	rigidbody1.gravityScaler = gravity;

	Circle acicle;
	acicle.position = Vector3(x, y, 0);
	acicle.radius = 20;

	Circle acicle2;
	acicle2.position = Vector3(600, 500, 0);
	acicle2.radius = 20;

	Matrix3x3 mat;

	while (sfw::stepContext())
	{
		/*if (sfw::getKey('S')) y -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('W')) y += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('A')) x -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('D')) x += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;*/

		if (sfw::getKey('S')) rigidbody1.AddForce(-transform1.GetUp() * speed);
		if (sfw::getKey('W')) rigidbody1.AddForce(transform1.GetUp() * speed);
		if (sfw::getKey('A')) rigidbody1.AddForce(-transform1.GetRight() * speed);
		if (sfw::getKey('D')) rigidbody1.AddForce(transform1.GetRight() * speed);
		if (sfw::getKey(' ')) rigidbody1.velocity = Vector3(rigidbody1.velocity.x, 100, rigidbody1.velocity.z);
		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;

		transform1.SetAngle(angle);
		transform1.SetScale(Vector3(200, 200, 0));

		rigidbody1.Integrate(&transform1, getDeltaTime());

		orbitalSpinner.SetParent(&transform1);
		orbitalSpinner.SetAngle(-sfw::getTime());

		transform2.SetParent(&orbitalSpinner);
		transform2.SetPosition(Vector3(.25f, .25f, 0));
		transform2.SetScale(Vector3(.5f, .5f, 0));

		Matrix4x4 m1 = Matrix3ToMatrix4(transform1.GetGlobalTransform(), 0.25);
		Matrix4x4 m2 = Matrix3ToMatrix4(transform2.GetGlobalTransform(), 0.1);

		sfw::drawTextureMatrix(handle, 0, WHITE, m1.m);
		sfw::drawTextureMatrix(handle, 0, MAGENTA, m2.m);

		if (sfw::getKey('S')) acicle.position.y -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('W')) acicle.position.y += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('A')) acicle.position.x -= sfw::getDeltaTime()  * speed;
		if (sfw::getKey('D')) acicle.position.x += sfw::getDeltaTime()  * speed;
		if (sfw::getKey('Q')) angle += sfw::getDeltaTime() * angularSpeed;
		if (sfw::getKey('E')) angle -= sfw::getDeltaTime() * angularSpeed;

		drawCircle(acicle.position.x, acicle.position.y, acicle.radius);
		drawCircle(acicle2.position.x, acicle2.position.y, acicle2.radius);
	}
	sfw::termContext();

	return 0;
}
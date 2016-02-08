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
	int  handle = sfw::loadTextureMap("./Textures/dino.png");

	Transform transform1;
	Transform transform2;
	Transform orbitalSpinner;

	Matrix3x3 mat;

	float x = 1, y = 1;
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

		transform1.SetAngle(angle);
		transform1.SetPosition(Vector3(x, y, 0));
		transform1.SetScale(Vector3(200, 200, 0));

		orbitalSpinner.SetParent(&transform1);
		orbitalSpinner.SetAngle(-sfw::getTime());

		transform2.SetParent(&orbitalSpinner);
		transform2.SetPosition(Vector3(.25f, .25f, 0));
		transform2.SetScale(Vector3(.5f, .5f, 0));

		Matrix4x4 m1 = Matrix3ToMatrix4(transform1.GetGlobalTransform(), 0.25);
		Matrix4x4 m2 = Matrix3ToMatrix4(transform2.GetGlobalTransform(), 0.1);

		sfw::drawTextureMatrix(handle, 0, WHITE, m1.m);
		sfw::drawTextureMatrix(handle, 0, MAGENTA, m2.m);
	}
	sfw::termContext();

	return 0;
}
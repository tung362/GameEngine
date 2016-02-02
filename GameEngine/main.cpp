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

#define ID_MAT3 Matrix3{1,0,0,0,1,0,0,0,1}

using namespace sfw;
using std::cout;
using std::endl;

int main()
{
	sfw::initContext();
	int  handle = sfw::loadTextureMap("./Textures/dino.png");

	float x = 400, y = 400;
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

		Matrix3x3 mat = Matrix3x3::Translate({ x,y,0 })
			* Matrix3x3::Scale(Vector3(410,410,410))
			* Matrix3x3::Rotate(angle);

		Matrix4x4 inMat = Matrix3ToMatrix4(mat.v);

		sfw::drawTextureMatrix(handle, 0, WHITE, inMat.m);
	}
	sfw::termContext();

	return 0;
}
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

		Matrix3x3 augoo;

		for (int i = 0; i < 9; ++i)
		{
			augoo.v[i] = i;
		}
		//augoo.v[0] = 0;
		//augoo.v[1] = 1;
		//augoo.v[2] = 2;

		//augoo.mm[0][0] = 0;
		//augoo.mm[0][1] = 1;
		//augoo.mm[0][2] = 2;


		for (int i = 1; i < 10; ++i)
		{
			std::cout << augoo.v[i-1] << ",";

			if (!(i % 3))
			{
				std::cout << std::endl;
			}
		}


		Matrix3x3 mat = Matrix3x3::Scale(Vector3(100, 100, 10)) * Matrix3x3::Translate({ x,y,0 });
						;
			//* Matrix3x3::Rotate(angle);

		/*for (int i = 0; i < 9; ++i)
		{
			std::cout << mat.v[i] << "   ";

			if (!(i % 3))
			{
				std::cout << std::endl;
			}
		}*/

		Matrix4x4 inMat = Matrix3ToMatrix4(mat);
		cout << endl << endl;
		for (int i = 1; i < 17; ++i)
		{
			cout << Matrix3ToMatrix4(mat.v).m[i-1] << ",";
			if (i % 4 == 0) cout << endl;
		}

		sfw::drawTextureMatrix(handle, 0, WHITE, inMat.m);
	}
	sfw::termContext();

	return 0;
}
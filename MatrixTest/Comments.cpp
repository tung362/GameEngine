//#include <iostream>
//#include <cstring>
//#include "TNL.h"

//using std::cout;
//using std::endl;

//Making it cross platform
/*#ifdef _WIN32 //Window
#define PRE __declspec(align(32))
#define PDS
#elif _GCC //Linix
#define PRE __attribute__((aligned(32)))
#define PDS
#endif*/

//Start at 32 bits take advantage of smd (Only for windows)
/*__declspec(align(32)) struct vec3
{

};*/

//int main()
//{

	/*Vector3 augoo(1, 0);
	cout << augoo.Magnitude() << endl;
	cout << augoo.Perpendicular().x << "," << augoo.Perpendicular().y << endl;
	cout << augoo.Normal(Vector3(10, 1)).x << "," << augoo.Normal(Vector3(10, 1)).y << endl;
	cout << augoo.GetAngle() << endl;

	Vector3 augoo2(1, 1);
	cout << augoo.Normal(Vector3(10, 1)).x << "," << augoo.Normal(Vector3(10, 1)).y << endl;
	cout << augoo.Reflection(augoo.Normal(augoo2)).x << "," << augoo.Reflection(augoo.Normal(augoo2)).y << endl;

	cout << endl << endl;*/

	/*Matrix3x3 trix(1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (int col = 0; col < 3; ++col)
	{
	cout << endl;
	for (int row = 0; row < 3; ++row) cout << trix.Identity().mm[row][col] << ",";
	}

	cout << endl;
	for (int col = 0; col < 3; ++col)
	{
	cout << endl;
	for (int row = 0; row < 3; ++row) cout << trix.GetTranspose().mm[row][col] << ",";
	}
	trix.Transpose();

	cout << endl;
	for (int col = 0; col < 3; ++col)
	{
	cout << endl;
	for (int row = 0; row < 3; ++row) cout << trix.mm[row][col] << ",";
	}*/

	//system("pause");
	//return 0;
//}

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
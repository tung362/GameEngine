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
#include "TNL.h"
#include <assert.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
#include <cmath>

using std::cout;
using std::endl;

void DebugVector3()
{
	//Default
	{
		Vector3 GG(4, 5, 0);
		assert(GG.x == 4 && GG.y == 5);
	}

	//Addition
	{
		Vector3 GG(1, 2, 0);
		Vector3 GG2(3, 4, 0);
		assert(GG + GG2 == Vector3(4, 6, 0));
		GG += GG2;
		assert(GG == Vector3(4, 6, 0));
	}

	//Subtraction
	{
		Vector3 GG(1, 2, 0);
		Vector3 GG2(3, 4, 0);
		assert(GG - GG2 == Vector3(-2, -2, 0));
		GG -= GG2;
		assert(GG == Vector3(-2, -2, 0));
	}

	//Multiplication
	{
		Vector3 GG(1, 2, 0);
		Vector3 GG2(3, 4, 0);
		assert(GG * GG2 == Vector3(3, 8, 0));
		assert(GG * 2 == Vector3(2, 4, 0));
		GG *= GG2;
		assert(GG == Vector3(3, 8, 0));
	}

	//Not Equal to
	{
		Vector3 GG(1, 2, 0);
		Vector3 GG3(3, 4, 0);
		assert(GG != GG3);
	}

	//Equal to
	{
		Vector3 GG(1, 2, 0);
		Vector3 GG2(1, 2, 0);
		assert(GG == GG2);
	}

	//Subscripts
	{
		Vector3 GG[3];
		GG[0] = Vector3(1, 2, 0);
		GG[1] = Vector3(3, 4, 0);
		GG[2] = Vector3(5, 6, 0);

		assert(GG[0].x == 1 && GG[0].y == 2);
		assert(GG[1].x == 3 && GG[1].y == 4);
		assert(GG[2].x == 5 && GG[2].y == 6);
	}

	//Distance
	assert(Distance(Vector3(2, 0, 0), Vector3(5.5, 0, 0)) == 3.5f);
}

void DebugMatrix3x3()
{
	Matrix3x3 TestTest1(1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	Matrix3x3 TestTest2(2, 2, 2,
		2, 2, 2,
		2, 2, 2);

	cout << "Original:" << endl;
	for (int col = 1; col < 4; ++col)
	{
		for (int row = 1; row < 4; ++row)
		{
			cout << TestTest1.mm[col - 1][row - 1] << ",";
			if (row % 3 == 0) cout << endl;
		}
	}
	cout << endl;

	cout << "Add:" << endl;
	Matrix3x3 test1 = TestTest1 * TestTest2;
	for (int col = 1; col < 4; ++col)
	{
		for (int row = 1; row < 4; ++row)
		{
			cout << test1.mm[col - 1][row - 1] << ",";
			if (row % 3 == 0) cout << endl;
		}
	}
	cout << endl;

	cout << "Added:" << endl;
	TestTest1 *= TestTest2;
	for (int col = 1; col < 4; ++col)
	{
		for (int row = 1; row < 4; ++row)
		{
			cout << TestTest1.mm[col - 1][row - 1] << ",";
			if (row % 3 == 0) cout << endl;
		}
	}
	cout << endl;

	cout << "Inverse:" << endl;
	Matrix3x3 poop1 = TestTest1.GetInverse();
	for (int col = 1; col < 4; ++col)
	{
		for (int row = 1; row < 4; ++row)
		{
			cout << poop1.mm[col - 1][row - 1] << ",";
			if (row % 3 == 0) cout << endl;
		}
	}
	cout << endl;

	cout << "Inversed:" << endl;
	TestTest1.Inverse();
	for (int col = 1; col < 4; ++col)
	{
		for (int row = 1; row < 4; ++row)
		{
			cout << TestTest1.mm[col - 1][row - 1] << ",";
			if (row % 3 == 0) cout << endl;
		}
	}
	cout << endl;
}

void DebugMatrix4x4()
{
	Matrix4x4 augoo(-4, 0, 0, 0,
		-1, 2, 0, 0,
		-4, 4, 4, 0,
		-1, -9, -1, 1);

	Matrix4x4 test(2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, -2, 2);

	Matrix4x4 inversed(-4, 0, 0, 0,
		-1, 2, 0, 0,
		-4, 4, 4, 0,
		-1, -9, -1, 1);

	//Display
	cout << "Display:" << endl;
	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << inversed.mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}

	//Add
	cout << "Add:" << endl;
	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << (augoo + test).mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}

	//Subtract
	cout << "Subtract:" << endl;
	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << (augoo - test).mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}

	//Multiply no edit
	cout << "Multiply no edit:" << endl;
	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << (augoo * test).mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}

	//Multiply edit
	cout << "Multiply no edit:" << endl;
	augoo *= test;
	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << augoo.mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}

	//Get Inverse
	cout << "Get Inverse:" << endl;
	Matrix4x4 augoo2 = inversed.GetInverse();

	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << augoo2.mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}

	//Inverse
	cout << "Inverse:" << endl;
	inversed.Inverse();
	for (int col = 1; col < 5; ++col)
	{
		for (int row = 1; row < 5; ++row)
		{
			cout << inversed.mm[col - 1][row - 1] << ",";
			if (row % 4 == 0) cout << endl;
		}
	}
}
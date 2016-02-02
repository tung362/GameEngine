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
	//Default
	{
		Matrix3x3 trix(1, 2, 3, 4, 5, 6, 7, 8, 9);
		assert(trix.mm[0][0] == 1 && trix.mm[0][1] == 4 && trix.mm[0][2] == 7);
	}

	//Addition
	{
		Matrix3x3 trix(1, 2, 3, 4, 5, 6, 7, 8, 9);
		Matrix3x3 trix2(1, 2, 3, 4, 5, 6, 7, 8, 9);

		Matrix3x3 Addtrix1 = trix + trix2;
		trix += trix2;

		assert(Addtrix1.mm[0][0] == 2 && Addtrix1.mm[0][1] == 8 && Addtrix1.mm[0][2] == 14);
		assert(trix.mm[0][0] == 2 && trix.mm[0][1] == 8 && trix.mm[0][2] == 14);
	}

	//Subtraction
	{
		Matrix3x3 trix(1, 2, 3, 4, 5, 6, 7, 8, 9);
		Matrix3x3 trix2(1, 2, 3, 4, 5, 6, 7, 8, 9);

		Matrix3x3 Addtrix1 = trix - trix2;
		trix -= trix2;

		assert(Addtrix1.mm[0][0] == 0 && Addtrix1.mm[0][1] == 0 && Addtrix1.mm[0][2] == 0);
		assert(trix.mm[0][0] == 0 && trix.mm[0][1] == 0 && trix.mm[0][2] == 0);
	}

	//Multiplication
	{
		Matrix3x3 trix(1, 2, 3, 4, 5, 6, 7, 8, 9);
		Matrix3x3 trix2(1, 2, 3, 4, 5, 6, 7, 8, 9);

		Matrix3x3 Addtrix1 = trix * trix2;
		trix *= trix2;

		//1 * 1 + 2 * 4 + 3 * 7 = 30
		//4 * 1 + 5 * 4 + 6 * 7 = 66
		//7 * 1 + 8 * 4 + 9 * 7 = 102
		assert(Addtrix1.mm[0][0] == 30 && Addtrix1.mm[0][1] == 66 && Addtrix1.mm[0][2] == 102);
		assert(trix.mm[0][0] == 30 && trix.mm[0][1] == 66 && trix.mm[0][2] == 102);
	}

	//Determinant
	{
		Matrix3x3 trix(1, 2, 3, 0, 1, 4, 5, 6, 0);
		assert(trix.Determinant() == 1);
	}

	//Inverse
	{
		Matrix3x3 trix(0, 1, 1, 2, 2, 2, 2, 1, 2);
		Matrix3x3 trix2 = trix.GetInverse();
		assert(trix2.mm[0][0] == -1 && trix2.mm[1][0] == 0.5f && trix2.mm[2][0] == -0);
		trix.Inverse();
		assert(trix.mm[0][0] == -1 && trix.mm[1][0] == 0.5f && trix.mm[2][0] == -0);
	}

	//Rotation
	{
		Matrix3x3 trix;
	}

	//Scale
	{
		Matrix3x3 trix;
	}

	//Translation
	{
		Matrix3x3 trix;
		assert(trix.Translate(Vector3(5, 8, 0)).mm[2][0] == 5 && trix.Translate(Vector3(5, 8, 0)).mm[2][1] == 8);
	}
}
#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Matrix4x4::Matrix4x4()
{
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col) mm[row][col] = 0;
	}
}

Matrix4x4::Matrix4x4(float r0c0, float r1c0, float r2c0, float r3c0, float r0c1, float r1c1, float r2c1, float r3c1, float r0c2, float r1c2, float r2c2, float r3c2, float r0c3, float r1c3, float r2c3, float r3c3)
{
		mm[0][0] = r0c0, mm[1][0] = r1c0, mm[2][0] = r2c0, mm[3][0] = r3c0,
		mm[0][1] = r0c1, mm[1][1] = r1c1, mm[2][1] = r2c1, mm[3][1] = r3c1,
		mm[0][2] = r0c2, mm[1][2] = r1c2, mm[2][2] = r2c2, mm[3][2] = r3c2;
		mm[0][3] = r0c3, mm[1][3] = r1c3, mm[2][3] = r2c3, mm[3][3] = r3c3;
}
#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Matrix4x4::Matrix4x4()
{
	for (int row = 0; row < 4; ++row)
	{
		for (int col = 0; col < 4; ++col) mm[col][row] = 0;
	}
}

Matrix4x4::Matrix4x4(float r0c0, float r1c0, float r2c0, float r3c0, float r0c1, float r1c1, float r2c1, float r3c1, float r0c2, float r1c2, float r2c2, float r3c2, float r0c3, float r1c3, float r2c3, float r3c3)
{
		mm[0][0] = r0c0, mm[0][1] = r1c0, mm[0][2] = r2c0, mm[0][3] = r3c0,
		mm[1][0] = r0c1, mm[1][1] = r1c1, mm[1][2] = r2c1, mm[1][3] = r3c1,
		mm[2][0] = r0c2, mm[2][1] = r1c2, mm[2][2] = r2c2, mm[2][3] = r3c2;
		mm[3][0] = r0c3, mm[3][1] = r1c3, mm[3][2] = r2c3, mm[3][3] = r3c3;
}

Matrix4x4 Matrix4x4::Identity()
{
	Matrix4x4 identity;
	int a = 0;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row)
		{
			if (col == a && row == a)
			{
				identity.mm[col][row] = 1;
				a += 1;
			}
			else identity.mm[col][row] = 0;
		}
	}
	return identity;
}

void Matrix4x4::Transpose()
{
	Matrix4x4 transposed;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) transposed.mm[col][row] = mm[row][col];
	}

	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) mm[col][row] = transposed.mm[col][row];
	}
}

Matrix4x4 Matrix4x4::Rotate(float radian)
{
	/*
	Matrix4x4 identity = Identity();
	identity.c[0] = Vector3(cosf(radian), sinf(radian), 0);
	identity.c[1] = Vector3(-sinf(radian), cosf(radian), 0);
	return identity;*/
	Matrix4x4 identity = Identity();
	identity.mm[0][0] = cosf(radian);
	identity.mm[0][1] = sinf(radian);
	identity.mm[1][0] = -sinf(radian);
	identity.mm[1][1] = cosf(radian);
	return identity;
}

Matrix4x4 Matrix4x4::Scale(const Vector2 & scale)
{
	Matrix4x4 identity = Identity();
	identity.mm[0][0] = scale.x;
	identity.mm[1][1] = scale.y;
	return identity;
}

Matrix4x4 Matrix4x4::Translate(const Vector2 & translation)
{
	Matrix4x4 identity = Identity();
	identity.mm[3][0] = translation.x;
	identity.mm[3][1] = translation.y;
	return identity;
}

Matrix4x4 Matrix4x4::GetTranspose() const
{
	Matrix4x4 transposed;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) transposed.mm[col][row] = mm[row][col];
	}
	return transposed;
}

float Matrix4x4::Determinant()
{
	return mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1]
		 + mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1]
		 + mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1]
		 + mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1]
		 - mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1]
		 - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1]
		 - mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1]
		 - mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1];
}

void Matrix4x4::Inverse()
{
	float oldDeterminate = Determinant();
	Matrix4x4 inverse;
	if (oldDeterminate != 0)
	{
		inverse.mm[1 - 1][1 - 1] = (mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[1 - 1][2 - 1] = (mm[1 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1]) / Determinant();
		inverse.mm[1 - 1][3 - 1] = (mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[1 - 1][4 - 1] = (mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1]) / Determinant();
		inverse.mm[2 - 1][1 - 1] = (mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1]) / Determinant();
		inverse.mm[2 - 1][2 - 1] = (mm[1 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[2 - 1][3 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][3 - 1]) / Determinant();
		inverse.mm[2 - 1][4 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1]) / Determinant();
		inverse.mm[3 - 1][1 - 1] = (mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[3 - 1][2 - 1] = (mm[1 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[3 - 1][3 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[3 - 1][4 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1]) / Determinant();
		inverse.mm[4 - 1][1 - 1] = (mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] + mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] + mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[4 - 1][2 - 1] = (mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[4 - 1][3 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[4 - 1][4 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1]) / Determinant();
	}

	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) mm[col][row] = inverse.mm[col][row];
	}
}

Matrix4x4 Matrix4x4::GetInverse()
{
	float oldDeterminate = Determinant();
	Matrix4x4 inverse;
	if (oldDeterminate != 0)
	{
		inverse.mm[1 - 1][1 - 1] = (mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[1 - 1][2 - 1] = (mm[1 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1]) / Determinant();
		inverse.mm[1 - 1][3 - 1] = (mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[1 - 1][4 - 1] = (mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1]) / Determinant();
		inverse.mm[2 - 1][1 - 1] = (mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1]) / Determinant();
		inverse.mm[2 - 1][2 - 1] = (mm[1 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[2 - 1][3 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][3 - 1]) / Determinant();
		inverse.mm[2 - 1][4 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][4 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1]) / Determinant();
		inverse.mm[3 - 1][1 - 1] = (mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[3 - 1][2 - 1] = (mm[1 - 1][1 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][4 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[3 - 1][3 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][4 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][4 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[3 - 1][4 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][2 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][4 - 1] + mm[1 - 1][4 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][4 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][4 - 1] * mm[3 - 1][1 - 1] - mm[1 - 1][4 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1]) / Determinant();
		inverse.mm[4 - 1][1 - 1] = (mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] + mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] + mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[4 - 1][2 - 1] = (mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][1 - 1] + mm[1 - 1][3 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][3 - 1] * mm[4 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][1 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][2 - 1] * mm[4 - 1][1 - 1]) / Determinant();
		inverse.mm[4 - 1][3 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][2 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][3 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[4 - 1][3 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[4 - 1][1 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[4 - 1][2 - 1]) / Determinant();
		inverse.mm[4 - 1][4 - 1] = (mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] + mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] + mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1]) / Determinant();
	}
	return inverse;
}

Vector2 Matrix4x4::GetXY()
{
	return Vector2(mm[0][3], mm[1][3]);
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4 & otherMatrix) const
{
	Matrix4x4 temp;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) temp.mm[col][row] = mm[col][row] + otherMatrix.mm[col][row];
	}
	return temp;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4 & otherMatrix) const
{
	Matrix4x4 temp;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) temp.mm[col][row] = mm[col][row] - otherMatrix.mm[col][row];
	}
	return temp;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4 & otherMatrix) const
{
	Matrix4x4 temp;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row)
		{
			for (int inner = 0; inner < 4; ++inner) temp.mm[col][row] += mm[col][inner] * otherMatrix.mm[inner][row];
		}
	}
	return temp;
}

void Matrix4x4::operator=(const Matrix4x4 & otherMatrix)
{
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) mm[col][row] = otherMatrix.mm[col][row];
	}
}

void Matrix4x4::operator+=(const Matrix4x4 & otherMatrix)
{
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) mm[col][row] += otherMatrix.mm[col][row];
	}
}

void Matrix4x4::operator-=(const Matrix4x4 & otherMatrix)
{
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) mm[col][row] -= otherMatrix.mm[col][row];
	}
}

//
void Matrix4x4::operator*=(const Matrix4x4 & otherMatrix)
{
	Matrix4x4 temp;
	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row)
		{
			for (int inner = 0; inner < 4; ++inner) temp.mm[col][row] += mm[col][inner] * otherMatrix.mm[inner][row];
		}
	}

	for (int col = 0; col < 4; ++col)
	{
		for (int row = 0; row < 4; ++row) mm[row][col] = temp.mm[row][col];
	}
}
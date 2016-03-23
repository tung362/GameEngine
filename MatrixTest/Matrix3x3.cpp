#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Matrix3x3::Matrix3x3()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col) mm[col][row] = 0;
	}
}

Matrix3x3::Matrix3x3(float r0c0, float r1c0, float r2c0, float r0c1, float r1c1, float r2c1, float r0c2, float r1c2, float r2c2)
{
	mm[0][0] = r0c0, mm[0][1] = r1c0, mm[0][2] = r2c0,
	mm[1][0] = r0c1, mm[1][1] = r1c1, mm[1][2] = r2c1,
	mm[2][0] = r0c2, mm[2][1] = r1c2, mm[2][2] = r2c2;
}

Matrix3x3 Matrix3x3::Identity()
{
	Matrix3x3 identity;
	int a = 0;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row)
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

void Matrix3x3::Transpose()
{
	Matrix3x3 transposed;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) transposed.mm[col][row] = mm[row][col];
	}

	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) mm[col][row] = transposed.mm[col][row];
	}
}

Matrix3x3 Matrix3x3::Rotate(float radian)
{
	/*
	Matrix3x3 identity = Identity();
	identity.c[0] = Vector3(cosf(radian), sinf(radian), 0);
	identity.c[1] = Vector3(-sinf(radian), cosf(radian), 0);
	return identity;*/
	/*Matrix3x3 identity = Identity();
	identity.mm[0][0] = cosf(radian);
	identity.mm[0][1] = sinf(radian);
	identity.mm[1][0] = -sinf(radian);
	identity.mm[1][1] = cosf(radian);
	return identity;*/
	Matrix3x3 identity = Identity();
	identity.c[0] = Vector3(cosf(radian), sinf(radian), 0);
	identity.c[1] = Vector3(-sinf(radian), cosf(radian), 0);
	return identity;
}

Matrix3x3 Matrix3x3::Scale(const Vector2 & scale)
{
	Matrix3x3 identity = Identity();
	identity.mm[0][0] = scale.x;
	identity.mm[1][1] = scale.y;
	return identity;
}

Matrix3x3 Matrix3x3::Translate(const Vector2 & translation)
{
	Matrix3x3 identity = Identity();
	identity.mm[2][0] = translation.x;
	identity.mm[2][1] = translation.y;
	return identity;
}

Matrix3x3 Matrix3x3::GetTranspose() const
{
	Matrix3x3 transposed;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) transposed.mm[col][row] = mm[row][col];
	}
	return transposed;
}

float Matrix3x3::Determinant()
{
	return mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] + mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[1 - 1][3 - 1] + mm[3 - 1][1 - 1] * mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] * mm[2 - 1][3 - 1] - mm[3 - 1][1 - 1] * mm[2 - 1][2 - 1] * mm[1 - 1][3 - 1] - mm[2 - 1][1 - 1] * mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1];
}

void Matrix3x3::Inverse()
{
	float oldDeterminate = Determinant();
	cout << oldDeterminate << endl;
	Matrix3x3 inverse;
	if (oldDeterminate != 0)
	{
		inverse.mm[0][0] = mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] / Determinant();
		inverse.mm[0][1] = mm[1 - 1][3 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1] / Determinant();
		inverse.mm[0][2] = mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] / Determinant();
		inverse.mm[1][0] = mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] / Determinant();
		inverse.mm[1][1] = mm[1 - 1][1 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][1 - 1] / Determinant();
		inverse.mm[1][2] = mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] / Determinant();
		inverse.mm[2][0] = mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] / Determinant();
		inverse.mm[2][1] = mm[1 - 1][2 - 1] * mm[3 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] / Determinant();
		inverse.mm[2][2] = mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] / Determinant();
	}

	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) mm[col][row] = inverse.mm[col][row];
	}
}

Matrix3x3 Matrix3x3::GetInverse()
{
	float oldDeterminate = Determinant();
	Matrix3x3 inverse;
	cout << oldDeterminate << endl;
	if (oldDeterminate != 0)
	{
		inverse.mm[0][0] = mm[2 - 1][2 - 1] * mm[3 - 1][3 - 1] - mm[2 - 1][3 - 1] * mm[3 - 1][2 - 1] / Determinant();
		inverse.mm[0][1] = mm[1 - 1][3 - 1] * mm[3 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[3 - 1][3 - 1] / Determinant();
		inverse.mm[0][2] = mm[1 - 1][2 - 1] * mm[2 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[2 - 1][2 - 1] / Determinant();
		inverse.mm[1][0] = mm[2 - 1][3 - 1] * mm[3 - 1][1 - 1] - mm[2 - 1][1 - 1] * mm[3 - 1][3 - 1] / Determinant();
		inverse.mm[1][1] = mm[1 - 1][1 - 1] * mm[3 - 1][3 - 1] - mm[1 - 1][3 - 1] * mm[3 - 1][1 - 1] / Determinant();
		inverse.mm[1][2] = mm[1 - 1][3 - 1] * mm[2 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[2 - 1][3 - 1] / Determinant();
		inverse.mm[2][0] = mm[2 - 1][1 - 1] * mm[3 - 1][2 - 1] - mm[2 - 1][2 - 1] * mm[3 - 1][1 - 1] / Determinant();
		inverse.mm[2][1] = mm[1 - 1][2 - 1] * mm[3 - 1][1 - 1] - mm[1 - 1][1 - 1] * mm[3 - 1][2 - 1] / Determinant();
		inverse.mm[2][2] = mm[1 - 1][1 - 1] * mm[2 - 1][2 - 1] - mm[1 - 1][2 - 1] * mm[2 - 1][1 - 1] / Determinant();
	}
	return inverse;
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3 & otherMatrix) const
{
	Matrix3x3 temp;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) temp.mm[col][row] = mm[col][row] + otherMatrix.mm[col][row];
	}
	return temp;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3 & otherMatrix) const
{
	Matrix3x3 temp;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) temp.mm[col][row] = mm[col][row] - otherMatrix.mm[col][row];
	}
	return temp;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3 & otherMatrix) const
{
	Matrix3x3 temp;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row)
		{
			for (int inner = 0; inner < 3; ++inner) temp.mm[col][row] += mm[col][inner] * otherMatrix.mm[inner][row];
		}
	}
	return temp;
}

void Matrix3x3::operator=(const Matrix3x3 & otherMatrix)
{
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) mm[col][row] = otherMatrix.mm[col][row];
	}
}

void Matrix3x3::operator+=(const Matrix3x3 & otherMatrix)
{
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) mm[col][row] += otherMatrix.mm[col][row];
	}
}

void Matrix3x3::operator-=(const Matrix3x3 & otherMatrix)
{
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) mm[col][row] -= otherMatrix.mm[col][row];
	}
}

void Matrix3x3::operator*=(const Matrix3x3 & otherMatrix)
{
	Matrix3x3 temp;
	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row)
		{
			for (int inner = 0; inner < 3; ++inner) temp.mm[col][row] += mm[col][inner] * otherMatrix.mm[inner][row];
		}
	}

	for (int col = 0; col < 3; ++col)
	{
		for (int row = 0; row < 3; ++row) mm[row][col] = temp.mm[row][col];
	}
}

Vector3 operator*(const Matrix3x3 &a, const Vector3 &b)
{
	Matrix3x3 newMatrix = a.GetTranspose();
	Vector3 newVector;

	newVector.x = DotPro(newMatrix.c[0], b);
	newVector.y = DotPro(newMatrix.c[1], b);
	newVector.z = DotPro(newMatrix.c[2], b);

	return newVector;
}
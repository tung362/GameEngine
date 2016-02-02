#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float x1, float y1, float z1)
{
	x = x1;
	y = y1;
	z = z1;
}

float Vector3::Magnitude()
{
	return sqrtf(x*x + y*y + z*z);
}

void Vector3::Normalize()
{
	float tempx = x / Magnitude();
	float tempy = y / Magnitude();
	float tempz = z / Magnitude();

	x = tempx;
	y = tempy;
	z = tempz;
}

Vector3 Vector3::CrossProduct(Vector3 b)
{
	Vector3 crossProduct;
	crossProduct.x = y*b.z - z*b.y;
	crossProduct.y = z*b.x - x*b.z;
	crossProduct.z = x*b.y - y*b.x;
	return crossProduct;
}

Vector3 Vector3::Normal()
{
	return Vector3(-y, x, 0);
}

Vector3 Vector3::Reflect(Vector3 normal)
{
	return -(2 * (DotPro(Vector3(x, y, z), normal))) * normal + Vector3(x, y, z);
}

float Vector3::GetAngle2D()
{
	float radians = (float)atan2(x, y);
	return (radians / PI) * 180;
}

void Vector3::operator-()
{
	x = -x;
	y = -y;
	z = -z;
}

void Vector3::operator=(Vector3 otherVec)
{
	x = otherVec.x;
	y = otherVec.y;
	z = otherVec.z;
}

Vector3 Vector3::operator+(Vector3 otherVec)
{
	Vector3 temp;
	temp.x = x + otherVec.x;
	temp.y = y + otherVec.y;
	temp.z = z + otherVec.z;
	return temp;
}

Vector3 Vector3::operator-(Vector3 otherVec)
{
	Vector3 temp;
	temp.x = x - otherVec.x;
	temp.y = y - otherVec.y;
	temp.z = z - otherVec.z;
	return temp;
}

Vector3 Vector3::operator*(Vector3 otherVec)
{
	Vector3 temp;
	temp.x = x * otherVec.x;
	temp.y = y * otherVec.y;
	temp.z = z * otherVec.z;
	return temp;
}

Vector3 Vector3::operator/(Vector3 otherVec)
{
	Vector3 temp;
	temp.x = x / otherVec.x;
	temp.y = y / otherVec.y;
	temp.z = z / otherVec.z;
	return temp;
}

Vector3 Vector3::operator*(float otherNum)
{
	Vector3 temp;
	temp.x = x * otherNum;
	temp.y = y * otherNum;
	temp.z = z * otherNum;
	return temp;
}

Vector3 Vector3::operator/(float otherNum)
{
	Vector3 temp;
	temp.x = x / otherNum;
	temp.y = y / otherNum;
	temp.z = z / otherNum;
	return temp;
}

void Vector3::operator+=(Vector3 otherVec)
{
	x += otherVec.x;
	y += otherVec.y;
	z += otherVec.z;
}

void Vector3::operator-=(Vector3 otherVec)
{
	x -= otherVec.x;
	y -= otherVec.y;
	z -= otherVec.z;
}

void Vector3::operator*=(Vector3 otherVec)
{
	x *= otherVec.x;
	y *= otherVec.y;
	z *= otherVec.z;
}

void Vector3::operator/=(Vector3 otherVec)
{
	x /= otherVec.x;
	y /= otherVec.y;
	z /= otherVec.z;
}

bool Vector3::operator==(Vector3 otherVec)
{
	//if (x == otherVec.x && y == otherVec.y) return true;
	if (x - FTL_EPSILON < otherVec.x && x + FTL_EPSILON > otherVec.x &&
		y - FTL_EPSILON < otherVec.y && y + FTL_EPSILON > otherVec.y &&
		z - FTL_EPSILON < otherVec.z && z + FTL_EPSILON > otherVec.z) return true;
	else return false;
}

bool Vector3::operator!=(Vector3 otherVec)
{
	if (x != otherVec.x || y != otherVec.y || z != otherVec.z) return true;
	else return false;
}

Vector3 operator*(float otherNum, Vector3 vec)
{
	Vector3 temp;
	temp.x = vec.x * otherNum;
	temp.y = vec.y * otherNum;
	temp.z = vec.z * otherNum;
	return temp;
}

void operator*=(float otherNum, Vector3 vec)
{
	vec.x *= otherNum;
	vec.y *= otherNum;
	vec.z *= otherNum;
}
#pragma once
#include <vector>
#include <list>
#define PI 3.14159265359
#define FTL_EPSILON 0.0001f

struct Vector3;
struct Matrix3x3;
struct AABB;
struct Circle;
struct Plane;
struct Ray;

/*Math Stuff*/
struct Vector3
{
public:
	float x;
	float y;
	float z;
	Vector3();
	Vector3(float x1, float y1, float z1);
	float Magnitude();
	void Normalize();
	Vector3 Normal();
	Vector3 CrossProduct(Vector3 b);
	Vector3 Perp();
	Vector3 Reflect(Vector3 normal);
	float GetAngle2D();
	static Vector3 SetAngle(float angle);

	void operator=(Vector3 otherVec);
	Vector3 operator+(Vector3 otherVec);
	Vector3 operator-(Vector3 otherVec);
	Vector3 operator*(Vector3 otherVec);
	Vector3 operator/(Vector3 otherVec);
	Vector3 operator*(float otherNum);
	Vector3 operator/(float otherNum);
	void operator+=(Vector3 otherVec);
	void operator-=(Vector3 otherVec);
	void operator*=(Vector3 otherVec);
	void operator/=(Vector3 otherVec);
	bool operator==(Vector3 otherVec);
	bool operator!=(Vector3 otherVec);
};
Vector3 operator*(float otherNum, Vector3 vec);
Vector3 operator-(Vector3 vec);
void operator*=(float otherNum, Vector3 vec);

struct Vector2
{
public:
	float x;
	float y;
	Vector2();
	Vector2(float x1, float y1);
	float Magnitude();
	void Normalize();
	Vector2 Normal();
	Vector2 Perp();
	Vector2 Reflect(Vector2 normal);
	float GetAngle2D();
	static Vector2 SetAngle(float angle);

	void operator=(Vector2 otherVec);
	Vector2 operator+(Vector2 otherVec);
	Vector2 operator-(Vector2 otherVec);
	Vector2 operator*(Vector2 otherVec);
	Vector2 operator/(Vector2 otherVec);
	Vector2 operator*(float otherNum);
	Vector2 operator/(float otherNum);
	void operator+=(Vector2 otherVec);
	void operator-=(Vector2 otherVec);
	void operator*=(Vector2 otherVec);
	void operator/=(Vector2 otherVec);
	bool operator==(Vector2 otherVec);
	bool operator!=(Vector2 otherVec);
};
Vector2 operator*(float otherNum, Vector2 vec);
Vector2 operator-(Vector2 vec);
void operator*=(float otherNum, Vector2 vec);

struct Matrix3x3
{
public:
	union
	{
		float   v[9];
		float   mm[3][3];
		Vector3 c[3];
	};

	Matrix3x3();
	Matrix3x3(float r0c0, float r1c0, float r2c0,
			  float r0c1, float r1c1, float r2c1,
			  float r0c2, float r1c2, float r2c2);
	static Matrix3x3 Identity();
	static Matrix3x3 Rotate(float radian);
	static Matrix3x3 Scale(const Vector2& scale);
	static Matrix3x3 Translate(const Vector2& translation);

	void Transpose();
	Matrix3x3 GetTranspose() const;
	float Determinant();
	void Cofactor();
	Matrix3x3 GetCofactor();
	void Adjugate();
	Matrix3x3 GetAdjugate();
	void Inverse();
	Matrix3x3 GetInverse();

	Matrix3x3 operator +(const Matrix3x3& otherMatrix) const;
	Matrix3x3 operator -(const Matrix3x3& otherMatrix) const;
	Matrix3x3 operator *(const Matrix3x3& otherMatrix) const;
	//Vector3 operator *(const Vector3& b) const;
	void operator =(const Matrix3x3& otherMatrix);
	void operator +=(const Matrix3x3& otherMatrix);
	void operator -=(const Matrix3x3& otherMatrix);
	void operator *=(const Matrix3x3& otherMatrix);
};
Vector3 operator*(const Matrix3x3 &a, const Vector3 &b);

struct Matrix4x4
{
public:
	union
	{
		float   m[16];
		float   mm[4][4];
	};
	Matrix4x4();
	Matrix4x4(float r0c0, float r1c0, float r2c0, float r3c0,
			  float r0c1, float r1c1, float r2c1, float r3c1,
			  float r0c2, float r1c2, float r2c2, float r3c2,
			  float r0c3, float r1c3, float r2c3, float r3c3);

	static Matrix4x4 Identity();
	static Matrix4x4 Rotate(float radian);
	static Matrix4x4 Scale(const Vector2& scale);
	static Matrix4x4 Translate(const Vector2& translation);

	void Transpose();
	Matrix4x4 GetTranspose() const;
	float Determinant();
	void Inverse();
	Matrix4x4 GetInverse();

	Matrix4x4 operator +(const Matrix4x4& otherMatrix) const;
	Matrix4x4 operator -(const Matrix4x4& otherMatrix) const;
	Matrix4x4 operator *(const Matrix4x4& otherMatrix) const;
	//Vector3 operator *(const Vector3& b) const;
	void operator =(const Matrix4x4& otherMatrix);
	void operator +=(const Matrix4x4& otherMatrix);
	void operator -=(const Matrix4x4& otherMatrix);
	void operator *=(const Matrix4x4& otherMatrix);
};
/*End of Math Stuff*/

/*Shapes*/
struct AABB
{
public:
	Vector2 position;
	Vector2 halfExtents; //Width, Height
	AABB();
	AABB(Vector2 newPosition, Vector2 newHalfExtents);
	Vector2 Min();
	Vector2 Max();
};

struct Circle
{
public:
	Vector2 position;
	float radius;
	Circle();
	Circle(Vector2 newPosition, float newRadius);
};

struct Plane
{
public:
	Vector2 position;
	Vector2 normal;
	Plane();
	Plane(Vector2 newPosition, Vector2 newNormal);
};

struct Ray
{
public:
	Vector2 position;
	Vector2 direction;
	float length;
	Ray();
	Ray(Vector2 newPosition, Vector2 newDirection, float newLength);
};

struct ConvexHull
{
	std::vector<Vector2> verts;
};

AABB operator*(Matrix3x3 &m, AABB &a);
Circle operator*(Matrix3x3 &m, Circle &a);
Ray operator*(Matrix3x3 &m, Ray &a);
Plane operator*(Matrix3x3 &m, Plane &a);
ConvexHull operator*(Matrix3x3 &m, ConvexHull &a);
/*End Of Shapes*/

/*Collision*/
struct CollisionData // Wrapper for Minimum Translation Vector
{
	bool     isOverlap;         // Did we collide?
	float    penetrationDepth;
	Vector2  collisionNormal;   // CollisionNormal * PenetrationDepth = Minimum Translation Vector, also called the impulse vector, very important! 
	Vector2  impulseVector;
	//Vector2  pointOfContact;    // optional.
};

CollisionData CollisionTest(AABB &a, AABB &b);
CollisionData CollisionTest(AABB &a, Circle &b);
CollisionData CollisionTest(AABB &a, Plane &b);
CollisionData CollisionTest(AABB &a, Ray &b);
CollisionData CollisionTest(Circle &a, Circle &b);
CollisionData CollisionTest(Circle &a, Plane &b);
CollisionData CollisionTest(Circle &a, Ray &b);
CollisionData CollisionTest(Ray &a, Plane &b);

//Reverse
CollisionData CollisionTest(Circle &b, AABB &a);
CollisionData CollisionTest(Plane &b, AABB &a);
CollisionData CollisionTest(Ray &b, AABB &a);
CollisionData CollisionTest(Plane &b, Circle &a);
CollisionData CollisionTest(Ray &b, Circle &a);
CollisionData CollisionTest(Plane &b, Ray &a);

//Convex Hull
CollisionData CollisionTest(ConvexHull &a, ConvexHull &b);
CollisionData CollisionTest(ConvexHull &a, Circle &b);
CollisionData CollisionTest(ConvexHull &a, Ray &b);
CollisionData CollisionTest(ConvexHull &a, Plane &b);
CollisionData CollisionTest(ConvexHull &a, AABB &b);

float Point_Plane_Dist(const Vector2 &a, const Plane &b);
float Ray_Plane_Dist(const Ray &a, const Plane &b);
/*End of Collision*/

/*Functions*/
Matrix4x4 Matrix3ToMatrix4(Matrix3x3 m, float Z);
Matrix4x4 Matrix3ToMatrix4(float *v, float Z);
float Distance(Vector3 vec1, Vector3 vec2);
float Distance(Vector2 vec1, Vector2 vec2);
float DotPro(Vector3 vec, Vector3 otherVec);
float DotPro(Vector2 vec, Vector2 otherVec);
Vector3 ILerp(Vector3 start, Vector3 target, float percentage);
Vector2 ILerp(Vector2 start, Vector2 target, float percentage);
float ILerp(float start, float target, float percentage);
Vector3 CrossProduct(Vector3 a, Vector3 b);
Vector3 SurfaceNormal(Vector3 a, Vector3 b, Vector3 c);
Vector3 Reflect(Vector3 vec1, Vector3 normal);
Vector2 Reflect(Vector2 vec1, Vector2 normal);
float Clamp(float min, float max, float value);
Vector3 Clamp(Vector3 min, Vector3 max, Vector3 value);
Vector2 Clamp(Vector2 min, Vector2 max, Vector2 value);
Vector2 Perp(Vector2 vec1);
Vector3 Perp(Vector3 vec1);

void DebugVector3();
void DebugMatrix3x3();
void DebugMatrix4x4();
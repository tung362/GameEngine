#pragma once
#include <vector>
#define PI 3.14159265359
#define FTL_EPSILON 0.0001f

struct Vector3;
struct Matrix3x3;
struct AABB;
struct Circle;
struct Plane;
struct Ray;

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
	Vector3 CrossProduct(Vector3 b);
	Vector3 Normal();
	Vector3 Reflect(Vector3 normal);
	float GetAngle2D();

	void operator-();
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
void operator*=(float otherNum, Vector3 vec);

//Translation * Rotation * Scale
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
	static Matrix3x3 Scale(const Vector3& scale);
	static Matrix3x3 Translate(const Vector3& translation);

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

Vector3 operator*(const Matrix3x3 &_A, const Vector3 &b);

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
};

/*class Transform
{
	Transform *parent;
	Vector3 position;
	Vector3 Scale;
	float angle;

public:
	Transform();
	~Transform();
	void SetParent(Transform * newParent);
	Matrix3x3 GetGlobalTransform() const;
	void SetLocalTransform(Matrix3x3 &);

	void SetPosition(const Vector3 & newPosition);
	void SetScale(const Vector3 & newScale);
	void SetAngle(float newAngle);

	Vector3 GetPosition();
	Vector3 GetScale();
	float GetAngle();
};*/

struct AABB
{
public:
	AABB();
	Vector3 m_Position;
	Vector3 m_Dimension;
	//Vector3 Min(Vector3 *v, size_t n);
	//Vector3 Max(Vector3 *v, size_t n);
	Vector3 Position(); //(min + max) / 2
	Vector3 Dimension(); //max - min
	void Rotate(float a);
};

struct Circle
{
public:

};

struct Plane
{
public:
	Vector3 position;
	Vector3 normal;
};

struct Ray
{
public:
	Vector3 position;
	Vector3 direction;
	float length;
};

/*struct CollisionData
{
	float PenetrationDepth; //Distance
	Vector3 CollisionNormal; //Direction
};

struct ConvexHull
{
	std::vector<Vector3> verts;
};

ConvexHull operator*(const Matrix3x3 &m, const ConvexHull &a);
Vector3 operator-(const Vector3 &a, )
CollisionData ITest_SAT(const ConvexHull &a, ConvexHull &b);*/

//Functions

//
/*AABB operator*(const Matrix3x3 &m, const AABB &a);
Circle operator*(const Matrix3x3 &m, const Circle &a);
Ray operator*(const Matrix3x3 &m, const Ray &a);
Plane operator*(const Matrix3x3 &m, const Plane &a);

bool ITest_AABB(const AABB &a, const AABB &b);
bool ITest_AABB_Circle(const AABB &a, const AABB &b);
bool ITest_AABB_Plane(const AABB &a, const AABB &b);
bool ITest_AABB_Ray(const AABB &a, const AABB &b);
bool ITest_Circle_Circle(const AABB &a, const AABB &b);
bool ITest_Circle_Plane(const AABB &a, const AABB &b);
bool ITest_Circle_Ray(const AABB &a, const AABB &b);
bool ITest_Circle_Plane(const AABB &a, const AABB &b);

Vector3 MTV_AABB(const AABB &a, const AABB &b);
Vector3 MTV_AABB_Circle(const AABB &a, const AABB &b);
Vector3 MTV_AABB_Plane(const AABB &a, const AABB &b);
Vector3 MTV_AABB_Ray(const AABB &a, const AABB &b);
Vector3 MTV_Circle_Circle(const AABB &a, const AABB &b);
Vector3 MTV_Circle_Plane(const AABB &a, const AABB &b);
Vector3 MTV_Circle_Ray(const AABB &a, const AABB &b);
Vector3 MTV_Circle_Plane(const AABB &a, const AABB &b);

float Point_Plane_Dist(const Vector3 &a, const Plane &b);
float Ray_Plane_Dist(const Ray &a, const Plane &b);


AABB GenAABB(Vector3 pts, size_t dim);
//w = h*sin(a) + w*cos(a)
//h = w*sin(a) + h*cos(a)
AABB Rotate(const AABB &aabb, float a);
Vector3 Min(Vector3 *v, size_t n);
Vector3 Max(Vector3 *v, size_t n);
float Clamp(float min, float max, float value);*/



//
Matrix4x4 Matrix3ToMatrix4(Matrix3x3 m);
Matrix4x4 Matrix3ToMatrix4(float *v);
float Distance(Vector3 vec1, Vector3 vec2);
float DotPro(Vector3 vec, Vector3 otherVec);
Vector3 ILerp(Vector3 start, Vector3 target, float percentage);
float ILerp(float start, float target, float percentage);
Vector3 CrossProduct(Vector3 a, Vector3 b);
Vector3 SurfaceNormal(Vector3 a, Vector3 b, Vector3 c);
Vector3 Reflect(Vector3 vec1, Vector3 normal);

void DebugVector3();
void DebugMatrix3x3();

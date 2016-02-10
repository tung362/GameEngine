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

struct Transform
{
	Transform *parent;
	std::list<Transform*> children;
	Vector3 position;
	Vector3 Scale;
	float angle;

public:
	Transform();
	~Transform();
	Matrix3x3 GetGlobalTransform() const;

	void SetParent(Transform * newParent);
	void SetPosition(const Vector3 & newPosition);
	void SetScale(const Vector3 & newScale);
	void SetAngle(float newAngle);

	Vector3 GetPosition() const;
	Vector3 GetScale() const;
	float GetAngle() const;

	Vector3 GetRight() const;
	Vector3 GetUp() const;
};

struct Rigidbody
{
public:
	Vector3 gravity;
	Vector3 velocity;
	Vector3 acceleration;
	Vector3 force;
	Vector3 jerk;
	float gravityScaler;
	float mass;
	float drag;
	float angularVelocity;
	float angularAcceleration;
	float torque;
	float angularDrag;
	Rigidbody();
	void AddForce(const Vector3 & newForce);
	void AddTorque(float newTorque);
	void Integrate(Transform * transform, float dt);
};


//Shapes//
struct AABB
{
public:
	Vector3 position;
	Vector3 halfExtents;
	AABB();
	Vector3 Min();
	Vector3 Max();
};

struct Circle
{
public:
	Vector3 position;
	float radius;
	Circle();
	Circle(Vector3 newPosition, float newRadius);
};

struct Plane
{
public:
	Vector3 position;
	Vector3 normal;
	Plane();
	Plane(Vector3 newPosition, Vector3 newNormal);
};

struct Ray
{
public:
	Vector3 position;
	Vector3 direction;
	float length;
	Ray();
	Ray(Vector3 newPosition, Vector3 newDirection, float newLength);
};

struct ConvexHull
{
	std::vector<Vector3> verts;
};

AABB operator*(const Matrix3x3 &m, const AABB &a);
Circle operator*(const Matrix3x3 &m, const Circle &a);
Ray operator*(const Matrix3x3 &m, const Ray &a);
Plane operator*(const Matrix3x3 &m, const Plane &a);
ConvexHull operator*(const Matrix3x3 &m, const ConvexHull &a);
//End Of Shapes//

//Collision//
bool CollisionTest(const AABB &a, const AABB &b);
bool CollisionTest(const AABB &a, const Circle &b);
bool CollisionTest(const AABB &a, const Plane &b);
bool CollisionTest(const AABB &a, const Ray &b);
bool CollisionTest(const Circle &a, const Circle &b);
bool CollisionTest(const Circle &a, const Plane &b);
bool CollisionTest(const Circle &a, const Ray &b);
bool CollisionTest(const Ray &a, const Plane &b);

Vector3 MTV_AABB(const AABB &a, const AABB &b);
Vector3 MTV_AABB_Circle(const AABB &a, const AABB &b);
Vector3 MTV_AABB_Plane(const AABB &a, const AABB &b);
Vector3 MTV_AABB_Ray(const AABB &a, const AABB &b);
Vector3 MTV_Circle_Circle(const Circle &a, const AABB &b);
Vector3 MTV_Circle_Plane(const Circle &a, const AABB &b);
Vector3 MTV_Circle_Ray(const Circle &a, const AABB &b);
Vector3 MTV_Ray_Plane(const Ray &a, const Plane &b);

float Point_Plane_Dist(const Vector3 &a, const Plane &b);
float Ray_Plane_Dist(const Ray &a, const Plane &b);
//End of Collision//


AABB GenAABB(Vector3 pts, size_t dim);
//w = h*sin(a) + w*cos(a)
//h = w*sin(a) + h*cos(a)
AABB Rotate(const AABB &aabb, float a);
Vector3 Min(Vector3 *v, size_t n);
Vector3 Max(Vector3 *v, size_t n);
float Clamp(float min, float max, float value);



//Functions
Matrix4x4 Matrix3ToMatrix4(Matrix3x3 m, float Z);
Matrix4x4 Matrix3ToMatrix4(float *v, float Z);
float Distance(Vector3 vec1, Vector3 vec2);
float DotPro(Vector3 vec, Vector3 otherVec);
Vector3 ILerp(Vector3 start, Vector3 target, float percentage);
float ILerp(float start, float target, float percentage);
Vector3 CrossProduct(Vector3 a, Vector3 b);
Vector3 SurfaceNormal(Vector3 a, Vector3 b, Vector3 c);
Vector3 Reflect(Vector3 vec1, Vector3 normal);

void DebugVector3();
void DebugMatrix3x3();

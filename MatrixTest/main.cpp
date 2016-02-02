#include <iostream>
#include <cstring>
#include "TNL.h"

using std::cout;
using std::endl;

int main()
{
	DebugVector3();
	DebugMatrix3x3();

	Vector3 augoo(1, 0, 0);
	Vector3 ray(1, -1, 0);
	cout << augoo.x << "," << augoo.y << "," << augoo.z << endl;
	cout << augoo.Normal().x << "," << augoo.Normal().y << "," << augoo.Normal().z << endl;
	cout << ray.Reflect(augoo.Normal()).x << "," << ray.Reflect(augoo.Normal()).y << "," << ray.Reflect(augoo.Normal()).z << endl;
	cout << Reflect(ray, augoo.Normal()).x << "," << Reflect(ray, augoo.Normal()).y << "," << Reflect(ray, augoo.Normal()).z << endl;

	system("pause");
	return 0;
}
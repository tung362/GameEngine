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
	cout << augoo.Perp().x << "," << augoo.Perp().y << "," << augoo.Perp().z << endl;
	cout << ray.Reflect(augoo.Perp()).x << "," << ray.Reflect(augoo.Perp()).y << "," << ray.Reflect(augoo.Perp()).z << endl;
	cout << Reflect(ray, augoo.Perp()).x << "," << Reflect(ray, augoo.Perp()).y << "," << Reflect(ray, augoo.Perp()).z << endl;

	system("pause");
	return 0;
}
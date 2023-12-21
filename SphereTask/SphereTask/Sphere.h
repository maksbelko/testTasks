#ifndef _SPHERE_H_
#define _SPHERE_H_

struct Sphere {
	double x0;
	double y0;
	double z0;
	int r;
	Sphere(double x = 0.0, double y = 0.0, double z = 0.0, int r = 1): x0(x), y0(y), z0(z), r(r) {}
};
#endif // !_SPHERE_H_



#ifndef _POINT_ON_SPHERE_H_
#define _POINT_ON_SPHERE_H_
#include "Sphere.h"
struct PointOnSphere {
	double x;
	double y;
	double z;
	PointOnSphere(double x, double y, double z) : x(x), y(y), z(z){}
	PointOnSphere(Sphere s = { 0.0, 0.0, 0.0, 1 });
	PointOnSphere(PointOnSphere& p);
	void Show();
	void setX(double x_);
	void setY(double y_);
	void setZ(double z_);

	//PointOnSphere* operator=(PointOnSphere* p);
};

#endif // _POINT_ON_SPHERE_H_

#include "PointOnSPhere.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
PointOnSphere::PointOnSphere(Sphere s) {
	/*
	srand(time(0));

	x' = x - x0;
	y' = y - x0;
	z' = z - x0;
	
	double xn = sqrt((rand() % (s.r * s.r * 100)) / 100);
	double yn = sqrt((rand() % int(s.r * s.r * 100 - xn * xn * 100)) / 100);
	double zn = sqrt(double(s.r) * double(s.r) - xn * xn - yn * yn);
	if (rand() * 2 / RAND_MAX < 1) {
		xn = -xn;
	}
	if (rand() * 2 / RAND_MAX < 1) {
		yn = -yn;
	}
	if (rand() * 2 / RAND_MAX < 1) {
		zn = -zn;
	}
	x = xn + s.x0;
	y = yn + s.y0;
	z = zn + s.z0;
	*/
}
void PointOnSphere::setX(double x_) {
	x = x_;
}
void PointOnSphere::setY(double y_) {
	y = y_;
}
void PointOnSphere::setZ(double z_) {
	z = z_;
}
void PointOnSphere::Show() {
	std::cout << "x: " << x << std::endl << "y: " << y << std::endl << "z: " << z << std::endl;
}
PointOnSphere::PointOnSphere(PointOnSphere& p) {
	x = p.x;
	y = p.y;
	z = p.z;
}
/*PointOnSphere* PointOnSphere::operator=(PointOnSphere* p) {
	
	this->x = p->x;
	this->y = p->y;
	this->z = p->z;
	return this;
}*/
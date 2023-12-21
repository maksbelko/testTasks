
#include "LinkedList.h"
#include "SelfBalancingBinaryTree.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

PointOnSphere* randPoint(Sphere s);
const int NUM_OF_TESTS = 5;
using namespace std;

int main() {
	srand(time(0));
	std::cout << "start program\n";
	Sphere mySphere = { 5.5, -4.3, -10.5, 22 };
	LinkedList listOfPoints;
	selfBalancedBinaryTree treeOfLenght;
	for (int i = 0; i < NUM_OF_TESTS; i++) {
		Node* sn = new Node();
		listOfPoints.addNodeToEnd(*sn);
	}
	Node* cur = listOfPoints.getFirst();
	std::cout << cur << std::endl;
	cur->point->Show();
	while(cur != nullptr) {
		/*
		x' = x - x0;
		y' = y - x0;
		z' = z - x0;
		*/
		std::cout << "\ntest";
		double xn = sqrt((rand() % (mySphere.r * mySphere.r * 100)) / 100);
		std::cout << "\ntest2";
		double yn = sqrt((rand() % int(mySphere.r * mySphere.r * 100 - xn * xn * 100)) / 100);
		double zn = sqrt(double(mySphere.r) * double(mySphere.r) - xn * xn - yn * yn);
		if (rand() * 2 / RAND_MAX < 1) {
			xn = -xn;
		}
		if (rand() * 2 / RAND_MAX < 1) {
			yn = -yn;
		}
		if (rand() * 2 / RAND_MAX < 1) {
			zn = -zn;
		}
		std::cout << "\ntest3";
		cur->point = new PointOnSphere(xn + mySphere.x0, yn + mySphere.y0, zn + mySphere.z0);
		PointOnSphere* p = cur->point;
		std::cout << "\ntest4";
		p->setX(xn + mySphere.x0);
		std::cout << "\ntest5";
		p->setY(yn + mySphere.y0);
		p->setZ(zn + mySphere.z0);
		std::cout << "\ntest6";
		p->Show();
		cur = cur->next;
		
	}
	std::cout << "filled points";
	while (listOfPoints.getFirst() != listOfPoints.getLast()) {
		Node* start = listOfPoints.getFirst();
		Node* finish = listOfPoints.getFirst()->next;
		while (finish != nullptr) {
			TreeNode TN = { start->point, finish->point };
			TreeNode* pTN = &TN;
			treeOfLenght.insert(pTN, pTN->val);
			std::cout << pTN->val << endl;
			finish = finish->next;
		}
		listOfPoints.deleteFirstNode();
	}
	std::cout << "done";
	TreeNode* max = treeOfLenght.findMax();
	std::cout << "Max lenght: " << max->val;
	std::cout << "Point 1:\n";
	max->point1->Show();
	std::cout << "Point 2:\n";
	max->point2->Show();
}

PointOnSphere* randPoint(Sphere s) {
	PointOnSphere* p = new PointOnSphere();
	srand(time(0));
	/*
	x' = x - x0;
	y' = y - x0;
	z' = z - x0;
	*/
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
	p->x = xn + s.x0;
	p->y = yn + s.y0;
	p->z = zn + s.z0;
	return p;
}
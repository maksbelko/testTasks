#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include "PointOnSPhere.h"
using namespace std;
struct Node {
	PointOnSphere* point;
	Node* next;
	Node* previous;

	Node();
	Node(PointOnSphere* p);
	Node(Sphere s);
	Node(const Node& n) : point(n.point), next(n.next), previous(n.previous) {}
	//Node* operator=			
};

#endif // !_NODE_H


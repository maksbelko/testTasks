#include "Node.h"
Node::Node() {
	point = nullptr;
	next = previous = nullptr;
}
Node::Node(PointOnSphere* p) {
	point = p;
	next = previous = nullptr;
}
Node::Node(Sphere s) {
	PointOnSphere p = { s };
	point = &p;
	next = previous = nullptr;
}
#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.h"
#include <iostream>
class LinkedList
{
private:
	Node* first;
	Node* last;
public:
	LinkedList();
	LinkedList(Node& f, Node& l);
	bool isEmpty() const;
	void addNodeToBeg(const Node& n);
	void addNodeToBeg(PointOnSphere* point);
	void addNodeToEnd(const Node& n);
	void addNodeToEnd(PointOnSphere* point);
	void deleteFirstNode();
	void deleteLastNode();
	void deleteNode(Node& n);
	void deleteNode(PointOnSphere* point);
	Node* getFirst();
	Node* getLast();
	Node* operator[] (const int i);
	~LinkedList();
};
#endif _LINKEDLIST_H_

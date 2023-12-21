#ifndef _TREENODE_H_
#define _TREENODE_H_
#include "PointOnSPhere.h"
#include <cmath>
struct TreeNode {
	double val;
	PointOnSphere* point1;
	PointOnSphere* point2;
	unsigned short height;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(double value);
	TreeNode(PointOnSphere* point1, PointOnSphere* point2);
	unsigned short getHeight();
	int balanceHeight();
	void resetHeight();
	TreeNode* rotateRight();
	TreeNode* rotateLeft();
	TreeNode* balanceNode();
};

#endif // !_TREENODE_H_


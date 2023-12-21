#include "TreeNode.h"
TreeNode::TreeNode(double value) {
	val = value;
	point1 = point2 = nullptr;
	height = 1;
	left = right = nullptr;
}

TreeNode::TreeNode(PointOnSphere* p1, PointOnSphere* p2) {
	val = sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y) + (p1->z - p2->z) * (p1->z - p2->z));
	point1 = p1;
	point2 = p2;
	height = 1;
	left = right = nullptr;
}
unsigned short TreeNode::getHeight() {
	if (this)
		return height;
	else
		return 0;
}

int TreeNode::balanceHeight() {
	return right->getHeight() - left->getHeight();
}

void TreeNode::resetHeight() {
	unsigned short hl = left->getHeight();
	unsigned short hr = right->getHeight();
	if (hl > hr)
		height = hl + 1;
	else
		height = hr + 1;
}
TreeNode* TreeNode::rotateRight() // right small turn
{
	TreeNode* n = left;
	left = n->right;
	n->right = this;
	this->resetHeight();
	n->resetHeight();
	return n;
}
TreeNode* TreeNode::rotateLeft() { // rigth small turn
	TreeNode* n = right;
	right = n->left;
	n->left = this;
	this->resetHeight();
	n->resetHeight();
	return n;
}
TreeNode* TreeNode::balanceNode() {
	this->resetHeight();
	if (this->balanceHeight() >= 2) {
		if (this->right->balanceHeight() < 0) { //big left
			this->right = this->rotateRight();
		}
		return this->rotateLeft();
	}
	if (this->balanceHeight() <= -2) {
		if (this->left->balanceHeight() > 0) { //big right
			this->left = this->rotateLeft();
		}
		return this->rotateRight();
	}
}


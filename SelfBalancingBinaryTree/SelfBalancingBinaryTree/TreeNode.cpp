#include "TreeNode.h"
#include <iostream>

using namespace std;
TreeNode::TreeNode(int value) {
	val = value;
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
	if (!right) {
		return -left->getHeight();
	}
	if (!left) {
		return right->getHeight();
	}
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
	cout << "\nRight small turn";
	TreeNode* n = left;
	left = n->right;
	n->right = this;
	this->resetHeight();
	n->resetHeight();

	return n;
}
TreeNode* TreeNode::rotateLeft() { // left small turn
	cout << "\nLeft small turn";
	TreeNode* n = right;
	right = n->left;
	n->left = this;
	this->resetHeight();
	n->resetHeight();
	
	return n;
}
TreeNode* TreeNode::balanceNode() {
	this->resetHeight();
	if (this->balanceHeight() == 2) {
		if (this->right->balanceHeight() < 0) { //big left
			cout << "\nstarting big left";
			this->right = this->rotateRight();
		}
		return this->rotateLeft();
	}
	if (this->balanceHeight() == -2) {
		if (this->left->balanceHeight() > 0) { //big right
			cout << "\nstarting big right";
			this->left = this->rotateLeft();
		}
		return this->rotateRight();
	}
	return this;
}


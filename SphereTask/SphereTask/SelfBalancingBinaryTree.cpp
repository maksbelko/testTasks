#include "SelfBalancingBinaryTree.h"
#include <iostream>

selfBalancedBinaryTree::selfBalancedBinaryTree(TreeNode* r) {
	root = r;
}

TreeNode* selfBalancedBinaryTree::find(TreeNode* n, double value) {
	while (n != nullptr) {
		if (n->val == value)
			return n;
		if (n->val > value)
			n = n->left;
		else if (n->val < value)
			n = n->right;
	}
	std::cout << "Can't find node with value of " << value;
	return nullptr;
}

TreeNode* selfBalancedBinaryTree::find(double value) {
	return find(root, value);
}

TreeNode* selfBalancedBinaryTree::insert(TreeNode* n, TreeNode* i) {
	if (n == nullptr) {
		return i;
	}
	if (i->val < n->val) {
		n->left = insert(n->left, i);
	}
	else {
		n->right = insert(n->right, i);
	}
	return n->balanceNode();
}
TreeNode* selfBalancedBinaryTree::insert(TreeNode* n) {
	return insert(root, n);
}

TreeNode* selfBalancedBinaryTree::insert(TreeNode* n, double value) {
	if (n == nullptr) {
		return new TreeNode(value);
	}
	if (value < n->val) {
		n->left = insert(n->left, value);
	}
	else {
		n->right = insert(n->right, value);
	}
	return n->balanceNode();
}
TreeNode* selfBalancedBinaryTree::insert(double value) {
	return insert(root, value);
}

TreeNode* selfBalancedBinaryTree::findMax(TreeNode* n)
{
	if (n->right == nullptr) {
		return n;
	}
	else {
		return findMax(n->left);
	}
}

TreeNode* selfBalancedBinaryTree::findMax()
{
	return findMax(root);
}

TreeNode* selfBalancedBinaryTree::findMin(TreeNode* n) {
	if (n->left == nullptr) {
		return n;
	}
	else {
		return findMin(n->left);
	}
}

TreeNode* selfBalancedBinaryTree::deleteMin(TreeNode* n) {
	if (n->left == 0)
		return n->right;
	n->left = deleteMin(n->left);
	return n->balanceNode();
}

TreeNode* selfBalancedBinaryTree::remove(TreeNode* n, double value) {
	if (n == nullptr)
		return nullptr;

	if (value < n->val) {
		n->left = remove(n->left, value);
	}
	else if (value > n->val) {
		n->right = remove(n->right, value);
	}
	else
	{
		TreeNode* l = n->left;
		TreeNode* r = n->right;
		delete n;
		if (!r) return l;
		TreeNode* min = findMin(r);
		min->right = deleteMin(r);
		min->left = l;
		return min->balanceNode();
	}
	return n->balanceNode();
}

TreeNode* selfBalancedBinaryTree::remove(double value) {
	return remove(root, value);
}
selfBalancedBinaryTree::~selfBalancedBinaryTree() {
	if (root) {
		while (root->left != nullptr) {
			remove(root->left->val);
		}
		while (root->right != nullptr) {
			remove(root->right->val);
		}
		delete root;
	}
}

#include "SelfBalancingBinaryTree.h"
#include <iostream>

selfBalancedBinaryTree::selfBalancedBinaryTree(TreeNode* r) {
	root = r;
}

TreeNode* selfBalancedBinaryTree::find(TreeNode* n, int value) {
	while (n != nullptr) {
		if (n->val == value)
			return n;
		if (n->val > value)
			n = n->left;
		else if (n->val < value)
			n = n->right;
	}
	//std::cout << "Can't find node with value of " << value << std::endl;
	return nullptr;
}
TreeNode* selfBalancedBinaryTree::find(int value) {
	return find(root, value);
}


TreeNode* selfBalancedBinaryTree::insert(TreeNode* n, int value) {
	if (find(root, value) != nullptr) {
		std::cout << "\nInsert canceled. Value already exists in tree";
		return nullptr;
	}
	if (n == nullptr) {
		return new TreeNode(value);
	}
	if (value < n->val) {
		n->left = insert(n->left, value);
	}
	else {
		n->right = insert(n->right, value);
	}
	std::cout << "\nvalue inserted: " << value;
	root = n->balanceNode();
	return root;
}

TreeNode* selfBalancedBinaryTree::insert(int value) {
	return insert(root, value);
}

TreeNode* selfBalancedBinaryTree::findMin(TreeNode* n) {
	if (n->left == nullptr) {
		return n;
	}
	else {
		return findMin(n->left);
	}
}

TreeNode* selfBalancedBinaryTree::theMinNodeToDelete(TreeNode* n) {
	if (n->left == 0)
		return n->right;
	n->left = theMinNodeToDelete(n->left);
	return n->balanceNode();
}

TreeNode* selfBalancedBinaryTree::remove(TreeNode* n, int value) {
	if (n == nullptr || find(n, value) == nullptr)
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
		std::cout << "\nNode deleted " << n->val;
		delete n;
		if (!r) return l;
		TreeNode* min = findMin(r);
		min->right = theMinNodeToDelete(r);
		min->left = l;
		root = min->balanceNode();
		return root;
	}
	root = n->balanceNode();
	return root;
}

TreeNode* selfBalancedBinaryTree::remove(int value) {
	return remove(root, value);
}
void selfBalancedBinaryTree::preOrder(TreeNode* r){ //!!DO NOT USE WHEN TREE IS EMPTY
	if (root == nullptr) {
		std::cout << "\nTree is empty!";
	}
	if (r != nullptr)
	{
		std::cout << r->val << " ";
		preOrder(r->left);
		preOrder(r->right);
	}
	
}
selfBalancedBinaryTree::~selfBalancedBinaryTree() {
	while (root->left != nullptr && root->right != nullptr){
		while (root->left != nullptr) {
			remove(root->left->val);
		}
		while (root->right != nullptr) {
			remove(root->right->val);
		}
	}
	if (root->left) {
		remove(root->left->val);
	}
	if (root->right) {
		remove(root->right->val);
	}
	remove(root->val);
}

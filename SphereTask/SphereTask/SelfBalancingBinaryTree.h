#ifndef _SELF_BALANCED_BINARY_TREE_H_
#define _SELF_BALANCED_BINARY_TREE_H_
#include "TreeNode.h"
#include <iostream>

class selfBalancedBinaryTree {

private:
	TreeNode* root;

public:
	selfBalancedBinaryTree(TreeNode* r = nullptr);
	TreeNode* find(TreeNode* n, double value);
	TreeNode* find(double value);
	TreeNode* insert(TreeNode* n, double value);
	TreeNode* insert(TreeNode* n, TreeNode* i);
	TreeNode* insert(TreeNode* n);//from root
	TreeNode* insert(double value);//from root
	TreeNode* findMax(TreeNode* n);
	TreeNode* findMax();
	TreeNode* findMin(TreeNode* n);
	TreeNode* deleteMin(TreeNode* n);
	TreeNode* remove(TreeNode* n, double value);
	TreeNode* remove(double value);
	~selfBalancedBinaryTree();
};

#endif // !_SELF_BALANCED_BINARY_TREE_H_


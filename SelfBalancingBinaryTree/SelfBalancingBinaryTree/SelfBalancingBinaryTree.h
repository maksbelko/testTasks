#ifndef _SELF_BALANCED_BINARY_TREE_H_
#define _SELF_BALANCED_BINARY_TREE_H_
#include "TreeNode.h"
#include <iostream>

class selfBalancedBinaryTree {

private:
	TreeNode* root;

public:
	selfBalancedBinaryTree(TreeNode* r);
	TreeNode* getRoot() {
		if (root != nullptr)
			return root;
		else
			return nullptr;
	};
	TreeNode* find(TreeNode* n, int value);
	TreeNode* find(int value);
	TreeNode* insert(TreeNode* n, int value);
	TreeNode* insert(int value);

	TreeNode* findMin(TreeNode* n);
	TreeNode* theMinNodeToDelete(TreeNode* n);
	TreeNode* remove(TreeNode* n, int value);
	TreeNode* remove(int value);
	void preOrder(TreeNode* r);//func from GB to show tree !!DO NOT USE WHEN TREE IS EMPTY
	~selfBalancedBinaryTree();
};

#endif // !_SELF_BALANCED_BINARY_TREE_H_


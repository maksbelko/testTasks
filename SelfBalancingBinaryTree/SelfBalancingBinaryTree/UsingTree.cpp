#include "SelfBalancingBinaryTree.h"
#include <iostream>

int main() {
	TreeNode* root = new TreeNode(15);
	selfBalancedBinaryTree* t = new selfBalancedBinaryTree(root);
	t->insert(10);
	t->insert(25);
	t->insert(6);
	t->insert(14);
	t->insert(3);
	t->insert(28);
	delete t;
	
}
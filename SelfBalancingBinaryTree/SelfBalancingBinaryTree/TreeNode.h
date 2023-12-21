#ifndef _TREENODE_H_
#define _TREENODE_H_

struct TreeNode {
	int val;
	unsigned short height;
	TreeNode* left;
	TreeNode* right;


	TreeNode(int value);
	unsigned short getHeight();
	int balanceHeight();
	void resetHeight();
	TreeNode* rotateRight();
	TreeNode* rotateLeft();
	TreeNode* balanceNode();
};

#endif // !_TREENODE_H_


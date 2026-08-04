#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


typedef struct BarryTree
{
	int val;
	struct BarryTree* left;
	struct BarryTree* right;
}Bt;


Bt* CreatNode(int x)
{
	Bt* newnode = (Bt*)malloc(sizeof(Bt));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->val = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}


Bt* TreeFind(Bt* root, int k)
{
	if (root == NULL)
		return NULL;

	if (root->val == k)
	{
		return root;
	}

	Bt* ret1 = TreeFind(root->left, k);
	if (ret1)
		return ret1;

	Bt* ret2 = TreeFind(root->right, k);
	if (ret2)
		return ret2;

}


void test01()
{
	//创造二叉树
	Bt* node1 = CreatNode(1);
	Bt* node2 = CreatNode(2);
	Bt* node3 = CreatNode(4);
	Bt* node4 = CreatNode(3);
	Bt* node5 = CreatNode(5);
	Bt* node6 = CreatNode(6);


	node1->left = node2;
	node1->right = node3;

	node2->left = node4;


	node3->left = node5;
	node3->right = node6;

	/*int k = 0;
	scanf("%d", &k);*/
	Bt*re = TreeFind(node1, 3);
	printf("%p", re);
}


int main()
{
	test01();
	return 0;
}




//判断镜像二叉树

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//typedef struct TreeNode TreeNode;
//
//bool _isSymmetric(TreeNode* leftTree, TreeNode* rightTree)
//{
//	if (leftTree == NULL && rightTree == NULL)
//		return true;
//
//	if (leftTree == NULL || rightTree == NULL)
//		return false;
//
//	if (leftTree->val != rightTree->val)
//		return false;
//
//	return _isSymmetric(leftTree->left, rightTree->right) && _isSymmetric(leftTree->right, rightTree->left);
//}
//bool isSymmetric(TreeNode* root) {
//	return _isSymmetric(root->left, root->right);
//}v



//判断平衡二叉树

//
//bool helpr(struct TreeNode* root, long long min, long long max)
//{
//	if (root == NULL)
//		return true;
//
//	if (root->val <= min || root->val >= max)
//		return false;
//	//框定范围（防止出现爷孙之间关系不匹配问题）
//	return helpr(root->left, min, root->val) && helpr(root->right, root->val, max);
//}
//
//bool isValidBST(struct TreeNode* root) {
//	return helpr(root, LONG_MIN, LONG_MAX);
//}
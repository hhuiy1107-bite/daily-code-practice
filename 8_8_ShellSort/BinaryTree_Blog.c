//#define  _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct BinaryTree
//{
//	int val;
//	struct BinaryTree* left;
//	struct BinaryTree* right;
//}Bt;
//
//
//Bt* CreatNode(int x)
//{
//	Bt* newnode = (Bt*)malloc(sizeof(Bt));
//	if (newnode == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	newnode->val = x;
//	newnode->left = NULL;
//	newnode->right = NULL;
//
//	return newnode;
//}
//
//
//
//int main()
//{
//	//´´Ôì¶þ²æÊ÷
//	Bt* node1 = CreatNode(1);
//	Bt* node2 = CreatNode(2);
//	Bt* node3 = CreatNode(4);
//	Bt* node4 = CreatNode(3);
//	Bt* node5 = CreatNode(5);
//	Bt* node6 = CreatNode(6);
//
//
//	node1->left = node2;
//	node1->right = node3;
//
//	node2->left = node4;
//
//	node3->left = node5;
//	node3->right = node6;
//
//	return 0;
//}
//
//

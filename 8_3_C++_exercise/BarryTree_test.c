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

//前序遍历
void PreOrder(Bt* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->val);

	PreOrder(root->left);
	PreOrder(root->right);

}

//中序遍历
void MidOrder(Bt* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	MidOrder(root->left);

	printf("%d ", root->val);

	MidOrder(root->right);
}


//节点个数
int TreeSize(Bt* root)
{
	if (root == NULL)
		return 0;

	int total = TreeSize(root->left) + TreeSize(root->right) + 1;

	return total;
}




int TreeLeafSize(Bt* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}



int TreeDepth(Bt* root)
{
	if (root == NULL)
		return 0;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}



int KSize(Bt* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return KSize(root->left, k - 1) + KSize(root->right, k - 1);
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
	
	//PreOrder(node1);

	//MidOrder(node1);


	/*int re = TreeSize(node1);
	printf("%d\n", re);*/


	//int re = TreeLeafSize(node1);
	//printf("%d ", re);

	//int re = TreeDepth(node1);
	//printf("%d ", re);

	//第k层有多少节点
	int k = 0;
	scanf("%d", &k);
	int re = KSize(node1,k);
	printf("%d ", re);
}


int main()
{
	test01();
	return 0;
}
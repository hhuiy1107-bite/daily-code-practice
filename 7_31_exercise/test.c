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


//中序 左子树  根  右子树
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


//后序： 左子树 右子树 根
void FinOrder(Bt* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	FinOrder(root->left);
	FinOrder(root->right);
	printf("%d ", root->val);
}


int TreeSize01(Bt* root)
{
	static size = 0;
	if (root == NULL)
	{
		return 0;
	}

	size++;
	TreeSize01(root->left);
	TreeSize01(root->right);
	return size;
}

int TreeSize02(Bt* root)
{
	return root == NULL ? 0 : TreeSize02(root->left) + TreeSize02(root->right) + 1;

}




int TreeDepth(Bt* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else

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
	//FinOrder(node1);


	//int re = TreeSize01(node1);
	//printf("%d\n", re);

	//TreeSize02(node1);

	TreeDepth(node1);
}



int main()
{
	test01();
	return 0;
}
#define  _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"

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



void TreeDestroy(Bt* root)
{
	
	if (root == NULL)
		return;
	TreeDestroy(root->left);
	TreeDestroy(root->right);
	
	free(root);
}

//层序遍历
void LevelOrder(Bt* root)
{
	Queue q;
	QInit(&q);
	QPush(&q, root);
	while (!QEmpty(&q))
	{
		int LevelSize = (&q)->size;
		for (int i = 0; i < LevelSize; i++)
		{
			Bt* front = QFront(&q);
			printf("%d ", front->val);
			QPop(&q);
			//用一个变量来接收二叉树中的根，防止Push不进去新节点,
			//如果不用front接收，那么Pop完就会丢失根，以至于找不到后续节点
			if (front->left)
				QPush(&q, front->left);

			if (front->right)
				QPush(&q, front->right);
		}
		printf("\n");
			
	}

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

	//TreeDestroy(node1);



	//层序遍历
	LevelOrder(node1);

}

//内联函数
inline int Add(int a, int b)
{
	return a + b;
}


void test02()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("%d ", c);
}


int main()
{
	//test01();
	test02();

	int i = NULL;
	printf("%d ", i);
	int* p = NULL;
	printf("%p", p);
	return 0;
}

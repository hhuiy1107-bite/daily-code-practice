#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


//判断是否为满二叉树

//bool isTreeComplete(Bt* root)
//{
//	Queue q;
//	QInit(&q);
//	QPush(&q, root);
//	while (!QEmpty(&q))
//	{
//		Bt* front = QFront(&q);
//		if (front == NULL)
//			break;
//		QPop(&q);
//
//		QPush(&q, front->left);
//		QPush(&q, front->right);
//	}
//
//	//此时要出第一个NULL，判断队列内是否还有非空
//	while (!QEmpty(&q))
//	{
//		Bt* a = QFront(&q);
//		if (a != NULL)
//		{
//			//推出前记得销毁
//			QDestroy(&q);
//			return false;
//
//		}
//		QPop(&q);
//	}
//	QDestroy(&q);
//	return true;
//}



void InsertSort()
{
	int a[] = { 33, 25, 21, 2, 67, 18, 9, 87 };
	int size = sizeof(a) / sizeof(int);

	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];

		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		//思考为什么放在外面，而不是放在循环内呢？
		a[end + 1] = tmp;

	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

}


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void BubbleSort()
{
	int a[] = { 33, 25, 21, 2, 67, 18, 9, 87 };
	int size = sizeof(a) / sizeof(int);

	for (int i = 0; i < size - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange++;
			}
		}
		if (exchange == 0)
			break;
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}



int main()
{
	InsertSort();
	BubbleSort();
	return 0;
}

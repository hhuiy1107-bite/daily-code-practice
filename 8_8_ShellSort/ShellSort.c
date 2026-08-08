//#define  _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;
//		for (int j = 0; j < gap; j++)
//		{
//			//²åÈëÅÅÐò
//			for (int i = j; i < n - 1; i++)
//			{
//				int end = i;
//				int tmp = a[end + 1];
//				while (end >= 0)
//				{
//					if (a[end] > tmp)
//					{
//						a[end + 1] = a[end];
//						end--;
//					}
//					else
//						break;
//				}
//				a[end + 1] = tmp;
//			}
//		}
//	}
//	
//	
//}
//
//
//
//void test01()
//{
//	srand((unsigned)time(NULL));
//	int* a = (int*)malloc(sizeof(int) * 10000);
//	int N = 10000;
//	for (int i = 0; i < N; i++)
//	{
//		a[i] = rand() %100 +1;
//	}
//	int size = N;
//	ShellSort(a, size);
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", a[i]);
//	}
//}
//
//
//
//
//int main()
//{
//	test01();
//	return 0;
//}
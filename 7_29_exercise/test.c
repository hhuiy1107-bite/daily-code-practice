#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"



void Creat()
{
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen fail");
		return;
	}
	

	for (int i = 0; i < 100; i++)
	{
		int x = rand() + 1;
		fprintf(fin, "%d\n",x);
	}
}


void Heaptest()
{
	int k = 0;
	printf("请输入k\n");
	scanf("%d", &k);

	//建一个k个数的小堆

	//
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fout fail");
		return;
	}

	TypeData* arr = (TypeData*)malloc(sizeof(TypeData) * k);
	
	for (int i = 0; i < k; i++)
	{
		int ret = fscanf(fout, "%d", &arr[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, k);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (arr[0] < x)
		{
			Swap(&arr[0], &x);
			AdjustDown(arr, 0, k);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr[i]);
	}

}


int main()
{
	srand((unsigned int)time(NULL));
	//Creat();
	Heaptest();
	return 0;
}
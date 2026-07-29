#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


void Swap(TypeData* p1, TypeData* p2)
{
	TypeData tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustDown(TypeData* a, int parent, int n)
{
	assert(a);

	int child = parent * 2 + 1;
	while (child < n)
	{
		//假设法建小堆
		if (child + 1 < n && a[child] > a[child + 1])//child满足child < n - 1,所以child + 1满足child + 1 < n;
		{
			++child;
		}

		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
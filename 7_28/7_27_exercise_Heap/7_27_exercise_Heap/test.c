#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


void Heaptest01()
{
	Hp hp;
	HpInit(&hp);
	TypeData arr[] = {1, 5, 6,4,3,8,7,9,12};
	for (int i = 0; i < sizeof(arr) / sizeof(TypeData) ; i++)
	{
		HpPush(&hp, arr[i]);
	}

	HpPop(&hp);

	HpDeatroy(&hp);

}



void Heaptest02()
{
	//原地建堆
	TypeData arr[] = { 1, 5, 6, 4, 3, 8, 7, 9, 12 };//若使用HpPush进行建堆，则需要另外开辟空间，而原地建堆则无需开辟额外空间
	for (int i = 1; i < sizeof(arr) / sizeof(TypeData); i++)
	{
		AdjustUp(arr, i);
	}
}


int main()
{
	//Heaptest01();

	Heaptest02();
	return 0;
}
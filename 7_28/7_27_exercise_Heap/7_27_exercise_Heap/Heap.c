#define  _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

//初始化
void HpInit(Hp* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}

//销毁
void HpDeatroy(Hp* php)
{
	free(php->a);
	php->a = NULL;

	php->size = php->capacity = 0;
}


//交换
void Swap(TypeData* p1, TypeData* p2)
{
	TypeData tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



  //向上调整算法
void AdjustUp(TypeData* a, int child)//注意这里穿得是下标
{
	//假设建大堆
	assert(a);

	while (child > 0)	
	{
		int parent = (child - 1) / 2;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
		} 
		else
		{
			break;
		}
	}
	
}





//插入
void HpPush(Hp* php, int x)
{
	assert(php);

	//插入前先判断空间是否充足
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		TypeData* tmp = (TypeData*)realloc(php->a, newcapacity * sizeof(TypeData));
		//判断是否扩容成功
		if (tmp == NULL)
		{
			return;
		}
		php->capacity = newcapacity;
		php->a = tmp;
	}


	php->a[php->size] = x;
	php->size++;

	//插入后向上调整算法，调整堆内元素顺序
	AdjustUp(php->a, php->size - 1);

}


//向下调整算法
void AdjustDown(TypeData* a, int parent, int n)
{
	assert(a);

	int child = parent * 2 + 1;
	while (child < n)
	{
		//假设法建大堆
		if (child + 1 < n && a[child] < a[child + 1])//child满足child < n - 1,所以child + 1满足child + 1 < n;
		{
			++child;
		}

		if (a[parent] < a[child])
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


//删除
void HpPop(Hp* php)
{
	assert(php);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

//向下调整算法
	AdjustDown(php->a, 0, php->size);
}


TypeData HpTop(Hp* php)
{
	assert(php);

	return php->a[0];
}


bool HpEmpty(Hp* php)
{
	assert(php);

	return php->size == 0;
}
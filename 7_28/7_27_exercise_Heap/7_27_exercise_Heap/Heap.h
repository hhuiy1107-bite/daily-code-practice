#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>



typedef int TypeData;

//堆结构体
typedef struct Heap
{
	TypeData* a;
	int size;
	int capacity;
}Hp;

//初始化
void HpInit(Hp* php);
//销毁
void HpDeatroy(Hp* php);

void HpPush(Hp* php, int x);

void HpPop(Hp* php);

void Swap(TypeData* p1, TypeData* p2);

void AdjustUp(TypeData* a, int child);

void AdjustDown(TypeData* a, int parent, int n);

TypeData HpTop(Hp* php);

bool HpEmpty(Hp* php);
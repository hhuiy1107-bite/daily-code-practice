#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

typedef int TypeData;

void AdjustDown(TypeData* a, int parent, int n);
 
void Swap(TypeData* p1, TypeData* p2);
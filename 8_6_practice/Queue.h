#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct BarryTree* QDataType;

typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;


typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QInit(Queue* pq);

void QPush(Queue* pq, QDataType x);

void QPop(Queue* pq);

QDataType QFront(Queue* pq);

QDataType QBack(Queue* pq);

bool QEmpty(Queue* pq);

void QDestroy(Queue* pq);

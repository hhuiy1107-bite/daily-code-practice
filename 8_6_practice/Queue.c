#define  _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"

//初始化
void QInit(Queue* pq)
{
	//判空防止空指针解引用
	assert(pq);

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}


//入队列
void QPush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("newnode malloc fail");
		return;
	}
	newnode->next = NULL;
	newnode->val = x;

	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}


//出队列
void QPop(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;

	// 关键修正：如果删完后头变空了，说明刚才删的是最后一个，尾巴也要置空
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}

	pq->size--;
}


QDataType QFront(Queue* pq)
{
	assert(pq);

	return pq->phead->val;
}

QDataType QBack(Queue* pq)
{
	assert(pq);

	return pq->ptail->val;
}


bool QEmpty(Queue* pq)
{
	assert(pq);

	return !pq->phead;
}


void QDestroy(Queue* pq)
{
	assert(pq);

	QNode* next = NULL;

	while (pq->phead)
	{
		next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	
	pq->ptail = pq->phead = NULL;
	pq->size = 0;
}

#include "DList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

PDListNode BuyNode(DataType data)
{
	PDListNode pNewNode = NULL;
	pNewNode = (PDListNode)malloc(sizeof(DListNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;

	return pNewNode;
}
void DListInit(PDListNode* Phead)
{
	assert(Phead);
	*Phead = BuyNode(0);
}
//β��
void DListPushBack(PDListNode pHead, DataType data)
{
	PDListNode pCur = pHead;
	PDListNode pNewNode = NULL;
	assert(pHead);
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	pNewNode = BuyNode(data);
	pCur->_pNext = pNewNode;
	pNewNode->_pPre = pCur;
}
//ͷ��
void DListPushFront(PDListNode pHead, DataType data)
{
	PDListNode pNewHead = NULL;
	assert(pHead);
	pNewHead = BuyNode(data);
	pNewHead->_pNext = pHead->_pNext;
	pHead->_pNext = pNewHead;
	pNewHead->_pPre = pHead;
	if(pNewHead->_pNext)
		pNewHead->_pNext->_pPre = pNewHead;
}

//βɾ
void DListPopBack(PDListNode pHead)
{
	PDListNode pTailNode = pHead;
	assert(pHead);
	while (pTailNode->_pNext)
	{
		pTailNode = pTailNode->_pNext;
	}
	if (pTailNode != pHead)
	{
		pTailNode->_pPre->_pNext = NULL;
	}
	free(pTailNode);
}
//ͷɾ
void DListPopFront(PDListNode pHead)
{
	PDListNode pDelNode = pHead;
	assert(pHead);
	pDelNode = pHead->_pNext;
	if (NULL == pHead)
		return;
	pHead->_pNext = pDelNode->_pNext;
	if(pDelNode->_pNext)
		pDelNode->_pNext->_pPre = pHead;
	free(pDelNode);
}
//����λ�õĲ���
void DListInsert(PDListNode pos, DataType data)
{
	PDListNode pNewNode = NULL;
	if (NULL == pos || NULL == pos->_pPre)
		return;

	pNewNode = BuyNode(data);

	//�Ȳ��ƻ�ԭ����Ľṹ
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;	
}
//����λ�õ�ɾ��
void DListErase(PDListNode pos)
{
	//��λ�ú�ͷ���λ�ò��ܽ���ɾ������
	if (NULL == pos || NULL == pos->_pPre)
		return;
	pos->_pPre->_pNext = pos->_pNext;
	if(pos->_pNext)//�������һ���ڵ�
		pos->_pNext->_pPre = pos->_pPre;
}
PDListNode DListFind(PDListNode pHead, DataType data)
{
	PDListNode pCur = NULL;
	assert(pHead);
	pCur = pHead->_pNext;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}
int DListEmpty(PDListNode pHead)
{
	assert(pHead);
	return NULL == pHead->_pNext;
}
//ֻ�����Ч�ڵ㣬��ɾ��ͷ���
void DListClear(PDListNode pHead)
{
	PDListNode pCur = NULL;
	pCur = pHead->_pNext;
	assert(pHead);
	while (pCur)
	{
		pHead->_pNext = pCur->_pNext;
		free(pCur);
		pCur = pHead->_pNext;
	}
}
//��������Ч�ڵ�ĸ���,������ͷ���
int DListSize(PDListNode pHead)
{
	assert(pHead);
	int count = 0;
	PDListNode pCur = NULL;
	pCur = pHead->_pNext;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
void DListDestory(PDListNode* pHead)
{
	assert(pHead);
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}
void PrintDList(PDListNode pHead)
{
	PDListNode pCur = NULL;
	assert(pHead);
	pCur = pHead->_pNext;
	while (pCur)
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}
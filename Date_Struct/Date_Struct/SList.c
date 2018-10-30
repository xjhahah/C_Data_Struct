#include "SList.h"

//�����ʼ��
void SListInit(PNode* pHead)  //���Ҫ�ı��ⲿʵ�ε�ָ�����Ҫ�ö���ָ��
{
	assert(pHead);
	*pHead = NULL;
}
//β��
void SListPushBack(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);  //pHeadһ������Ϊ�գ���ΪpHead��һ������ָ��
	//����Ϊ��
	pNewNode = BuySListNode(data);
	if (NULL == *pHead)
		*pHead = pNewNode;
	//����ǿ�
	else
	{
		PNode pCur = *pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;
		pCur->_pNext = pNewNode;
	}
}

//ͷ��
void SListPushFront(PNode* pHead, DataType data)
{
	PNode pNewNode = NULL;
	assert(pHead);
	pNewNode = BuySListNode(data);
	if (NULL == pNewNode)
		return;
	pNewNode->_pNext = *pHead;
	*pHead = pNewNode;
}

//βɾ
void SListPopBack(PNode* pHead)
{
	//assert �� if ����
	//assertֻ��debug�Ż��У���������������Ƿ��Żᴥ�������� if ���ж������Ϸ�����������ж�����
	assert(pHead);
	if (NULL == pHead)
		return;
	//�ǿ�
	else if (NULL == (*pHead)->_pNext)
	{
		//ֻ��һ���ڵ�
		free(*pHead);
		(*pHead) = NULL;
	}
	else
	{
		//�ж���ڵ�
		PNode pCur = *pHead;
		while (pCur->_pNext->_pNext)
			pCur = pCur->_pNext;
		free(pCur->_pNext);
		pCur->_pNext = NULL;
	}
}

//ͷɾ
void SListPopFront(PNode* pHead)
{
	assert(pHead);
	//�����������ʲô��û��ֱ�ӷ���
	if (NULL == *pHead)
		return;
	else
	{
		//���Դ���ֻ��һ���ڵ�Ͷ���ڵ�
		PNode pDel = NULL;
		pDel = *pHead;
		*pHead = pDel->_pNext;
		free(pDel);
	}
}
PNode SListFind(PNode pHead, DataType data)
{
	PNode pCur = pHead;
	while (pCur)
	{
		if (pCur->_data == data)
			return pCur;
		else
			pCur = pCur->_pNext;
	}
	return NULL;
}
//����λ�õĲ���
void SListInsert(PNode* pHead, DataType data, PNode pos)
{
	PNode pNewNode = NULL;
	assert(pHead);
	if (NULL == *pHead || NULL == pos)
		return;
	pNewNode = BuySListNode(data);
	if (NULL == pNewNode)
		return;
	else
	{
		pNewNode->_pNext = pos->_pNext;
		pos->_pNext = pNewNode;
	}
}
//����λ�õ�ɾ��
void SListErease(PNode* pHead, PNode pos)
{
	assert(pHead);
	if (NULL == *pHead || NULL == pos)
		return;
	if (pos == *pHead)
		SListPopFront(pHead);
	else
	{
		PNode pCur = *pHead;
		while (pCur && pCur->_pNext != pos) //���pCur��û���ߵ���
			pCur = pCur->_pNext;
		if (pCur)
		{
			pCur->_pNext = pos->_pNext;
			free(pos);
		}
	}
}
//��������٣�������ͷɾ�����û����������ʹ����ڴ�й©
void SListDestory(PNode* pHead)
{
	SListClear(pHead);
}
//�����нڵ����
int SListSize(PNode* pHead)
{
	int count = 0;
	PNode pCur = NULL;
	pCur = *pHead;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//���������������������������ͬ
void SListClear(PNode* pHead)
{
	PNode pDelNode = NULL;
	assert(pHead);
	while (*pHead)
	{
		pDelNode = *pHead;
		*pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}
//����β�ڵ�
PNode SListBack(PNode pHead)
{
	PNode pCur = pHead;
	if (NULL == pHead)
		return NULL;
	while (pCur->_pNext)
		pCur = pCur->_pNext;
	return pCur;
}
///////////����������//////////////////////
void PrintListFromTailToHead(PNode pHead)  //�ݹ�ʱ�临�Ӷ�O(N) �ռ临�Ӷ�O(N)
{
	if (pHead)
	{
		PrintListFromTailToHead(pHead->_pNext);
		printf("%d ", pHead->_data);
	}
	printf("\n");
}

//ɾ����ͷ�������һ����β�ڵ㣨���ܱ�������
//������õķ�������pos->_pNext��data����posλ�ô���data��Ȼ��ɾ��pos->_pNextλ�õ�data
void DeleteNotTailNode(PNode pos)
{
	PNode pDelNode = NULL;
	if (NULL == pos && NULL == pos->_pNext)
		return;
	pDelNode = pos->_pNext;
	pos->_data = pDelNode->_data;
	pos->_pNext = pDelNode->_pNext;
	free(pDelNode);
}
//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
void InsertPosFront(PNode pos, DataType data)
{
	PNode pNewNode = NULL;
	if (NULL == pos)
		return;
	pNewNode = BuySListNode(pos->_data);
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
	pos->_data = data;
}
//������ʵ��Լɪ��
PNode JosephCircle(PNode* pHead, const int M)
{
	PNode pCur = NULL;
	PNode pDelNode = NULL;
	assert(pHead);
	if (NULL == *pHead)
		return NULL;
	pCur = *pHead;
	//����
	while (pCur->_pNext != pCur)
	{
		int count = M;
		while (--count)
		{
			pCur = pCur->_pNext;//����
		}
		//ɾ�ڵ�,�滻��ɾ��	
		pDelNode = pCur->_pNext;
		pCur->_data = pDelNode->_data;
		pCur->_pNext = pDelNode->_pNext;
	}
	*pHead = pCur;  //�����ܰѵ�һ���ڵ�ɾ����
	return *pHead;
}
//ð������
void SListBubbleSort(PNode pHead)
{
	PNode pPre = NULL;
	PNode pCur = NULL;
	PNode pTail = NULL;
	if (NULL == pHead || NULL == pHead->_pNext)
		return;
	while (pHead != pTail)
	{
		int IsChange = 0;
		pPre = pHead;
		pCur = pPre->_pNext;
		while (pCur != pTail)
		{

			if (pPre->_data > pCur->_data)
			{
				int temp = pPre->_data;
				pPre->_data = pCur->_data;
				pCur->_data = temp;
				IsChange = 1;
			}
			pPre = pCur;
			pCur = pPre->_pNext;
		}
		if (!IsChange)
			return;
		pTail = pPre;
	}
}
//�����������,�����������ָ��
void ReverseSList(PNode* pHead)
{
	PNode pPre = NULL;
	PNode pCur = NULL;
	PNode pNext = NULL;
	assert(pHead);
	if (NULL == *pHead || NULL == (*pHead)->_pNext)
		return;
	pCur = *pHead;
	while (pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	*pHead = pPre;
}
//����,.ͷ�巨�������������������⣿���Կ����Ƚ����Ͽ�Ȼ�������������������
PNode ReverseSListOP(PNode pHead)
{
	PNode pNewHead = NULL;
	PNode pCur = NULL;
	PNode pNext = NULL;
	if (NULL == pHead)
		return NULL;
	pCur = pHead;
	while (pCur)
	{
		pNext = pCur->_pNext;
		pCur->_pNext = pNewHead;
		pNewHead = pCur;
		pCur = pNext;
	}
	return pNewHead;
}

//�ϲ��������������ϲ�֮����Ȼ����
PNode MergeSList(PNode pHead1, PNode pHead2)
{
	PNode pNewHead = NULL;
	PNode pTailNode = NULL;
	PNode pL1 = pHead1;
	PNode pL2 = pHead2;
	//��һ
	if (NULL == pHead1)
		return pHead2;
	if (NULL == pHead2)
		return pHead1;
	if (NULL == pHead1 && NULL == pHead2)
		return pHead1;
	//����
	/*if (NULL == pHead1 || NULL == pHead2)
		return pHead1 ? pHead2 : pHead1;*/

		//����������Ϊ��
	if (pL1->_data < pL2->_data)
	{
		pNewHead = pL1;
		pL1 = pL1->_pNext;
	}
	else
	{
		pNewHead = pL2;
		pL2 = pL2->_pNext;
	}
	pTailNode = pNewHead;
	while (pL1 && pL2)
	{
		if (pL1->_data < pL2->_data)
		{
			pTailNode->_pNext = pL1;
			pL1 = pL1->_pNext;
		}
		else
		{
			pTailNode->_pNext = pL2;
			pL2 = pL2->_pNext;
		}
		pTailNode = pTailNode->_pNext;
	}
	if (pL1)
	{
		pTailNode->_pNext = pL1;
	}
	else
	{
		pTailNode->_pNext = pL2;
	}
	return pNewHead;
}
//����������м��㣬Ҫ��ֻ�ܱ���һ��
//˼·������ָ��
PNode FindMidNode(PNode pHead)
{
	PNode pSlow = NULL;
	PNode pFast = NULL;
	if (NULL == pHead)
		return NULL;
	pSlow = pHead;
	pFast = pHead;
	while (pFast && pFast->_pNext)   //pFast�ߵÿ죬����ֻ�����ָ������Ϊѭ������
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}

//�����������ĵ�K���ڵ㣬Ҫ��ֻ�ܱ���һ������
PNode FindLastKNode(PNode pHead, int K)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	if (NULL == pHead || K <= 0)
		return NULL;
	//����pFast��K����
	while (K--)
	{
		//���ȱ�֤pFast��Ϊ��
		if (pFast)
			return NULL;
		pFast = pFast->_pNext;
	}
	//Ȼ�����ָ��һ����
	while (pFast)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}
	return pSlow;
}
//�ж������޻��������Ƿ��ཻ
int IsCrossWithoutCircle(PNode pHead1, PNode pHead2)
{
	PNode pTail1 = pHead1;
	PNode pTail2 = pHead2;
	if (NULL == pHead1 || NULL == pHead2)
		return 0;
	//�ҵ�һ�������β�ڵ�
	while (pTail1->_pNext)
	{
		pTail1 = pTail1->_pNext;
	}
	//�ҵڶ��������β�ڵ�
	while (pTail2->_pNext)
	{
		pTail2 = pTail2->_pNext;
	}
	return pTail1 == pTail2;
}
//�ж������޻��������Ƿ��ཻ,���ཻ���󽻵�
PNode GetCrossNode(PNode pHead1, PNode pHead2)
{
	int size1 = 0, size2 = 0;
	int gap = 0;
	PNode pCur1 = pHead1;
	PNode pCur2 = pHead2;
	if (!(IsCrossWithoutCircle(pHead1, pHead2))) //������ཻ
		return NULL;
	//�����������нڵ����
	while (pCur1)
	{
		size1++;
		pCur1 = pCur1->_pNext;
	}
	while (pCur2)
	{
		size2++;
		pCur2 = pCur2->_pNext;
	}
	gap = size1 - size2;
	pCur1 = pHead1;
	pCur2 = pHead2;
	if (gap > 0)
	{
		while (gap--)
		{
			pCur1 = pCur1->_pNext;
		}
	}
	else if (gap < 0)
	{
		while (gap++)
		{
			pCur2 = pCur2->_pNext;
		}
	}
	else
	{
		while (pCur1 != pCur2)
		{
			pCur1 = pCur1->_pNext;
			pCur2 = pCur2->_pNext;
		}
	}
	return pCur1;
}

//�ж������Ƿ����?���������󻷵ĳ���
PNode IsCircle(PNode pHead)
{
	PNode pFast = pHead;
	PNode pSlow = pHead;
	while (pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if (pFast == pSlow)
			return pSlow;    //һ������
	}
	return NULL;   //һ��������
}
int GetCircleLen(PNode pHead)
{
	PNode pMeetNode = IsCircle(pHead);
	PNode pCur = pMeetNode;
	int count = 1;
	if (NULL == pMeetNode)
		return 0;
	if (pCur->_pNext != pMeetNode)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
//�������󻷵���ڵ㣬�����л���ʽ�ó����㹫ʽ ��֤��������
PNode GetEnterNode(PNode pHead, PNode pMeetNode)
{
	PNode pH = pHead;
	PNode pM = pMeetNode;
	if (NULL == pHead || NULL == pMeetNode)
		return NULL;
	while (pH != pM)
	{
		pH = pH->_pNext;
		pM = pM->_pNext;
	}
	return pH;
}
//�ж����������Ƿ��ཻ�����ཻ���󽻵㣬������ܴ���
//һ��������һ���������϶������ཻ
int IsListCrossWithCircle(PNode pHead1, PNode pHead2)
{
	PNode pMeetNode1 = IsCircle(pHead1);
	PNode pMeetNode2 = IsCircle(pHead2);

	//�����������������,��������������һ���ڵ㣬�����ڵ��Ƿ����
	if (NULL == pMeetNode1 && NULL == pMeetNode2)
	{
		PNode pTail = NULL;
		PNode pTail2 = NULL;
		if (NULL == pHead1 || NULL == pHead2)
			return 0;
		pTail = pHead1;
		pTail2 = pHead2;
		while (pTail->_pNext)
		{
			pTail = pTail->_pNext;
		}
		while (pTail2->_pNext)
		{
			pTail2 = pTail2->_pNext;
		}
		if (pTail == pTail2)
		{
			return 1;
		}
	}
	//���������������
	else if (pMeetNode1 && pMeetNode2)
	{
		PNode pCur = pMeetNode1;
		do
		{
			if (pCur == pMeetNode2)
				return 2;
			pCur = pCur->_pNext;
		} while (pCur != pMeetNode1);
	}
	return 0;
}
//��������ĸ���
//˼·�� 1����ԭ����ÿ���ڵ�������ֵ��ͬ�Ľڵ�
//       2�����²���ڵ�����ָ����ֵ
//       3����������½ڵ�������в�����
PComplexNode CopyComplexList(PComplexNode pHead)
{
	PComplexNode pOldNode = pHead;
	PComplexNode pNewNode = NULL;
	PComplexNode pNewHead = NULL;
	if (NULL == pHead)
		return NULL;
	// 1����ԭ����ÿ���ڵ�������ֵ��ͬ�Ľڵ�
	while(pOldNode)
	{
		pNewNode = (PComplexNode)malloc(sizeof(ComplexNode));
		if (NULL == pNewNode)
			return NULL;
		pNewNode->_data = pOldNode->_data;
		pNewNode->_pNext = NULL;
		pNewNode->_pRandom = NULL;

		pNewNode->_pNext = pOldNode->_pNext;
		pOldNode->_pNext = pNewNode;
		pOldNode = pNewNode->_pNext;
	}
	// 2�����²���ڵ�����ָ����ֵ
	pOldNode = pHead;
	while (pOldNode->_pNext)
	{
		pNewNode = pOldNode->_pNext;
		if (NULL == pOldNode->_pNext)
			pNewNode->_pRandom = NULL;
		else
			pNewNode->_pRandom = pOldNode->_pRandom->_pNext;
		pOldNode = pNewNode->_pNext;
	}
	// 3����������½ڵ�������в�����
	pOldNode = pHead;
	pNewHead = pOldNode->_pNext;
	while (pOldNode->_pNext)
	{
		pNewNode = pOldNode->_pNext;
		pOldNode->_pNext = pNewNode->_pNext;
		pOldNode = pNewNode; 
	}
	return pNewHead;
}

//��������������������ͬ������
void UnionSet(PNode pHead1, PNode pHead2)
{
	while (NULL != pHead1 && NULL != pHead2)
	{
		if (pHead1->_data < pHead2->_data)
		{
			pHead1 = pHead1->_pNext;
		}
		else if (pHead1->_data > pHead2->_data)
		{
			pHead2 = pHead2->_pNext;
		}
		else
		{
			printf("pHead1->_data=%d, pHead2->_data=%d", pHead1->_data,pHead2->_data);
			pHead1 = pHead1->_pNext;
			pHead2 = pHead2->_pNext;
		}
	}
}
////////////////////////////////////////////////////////
PNode BuySListNode(DataType data)
{
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
		return NULL;
	pNewNode->_pNext = NULL;
	pNewNode->_data = data;
	return pNewNode;
}
void PrintList(PNode pHead)
{
	PNode pCur = pHead;
	while (pCur)
	{
		printf("%d-->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

#if 0
void TestComplexList()
{
	ComplexNode node1, node2, node3, node4;
	PComplexNode pHead = NULL;
	node1._data = 1;
	node1._pNext = &node2;
	node1._pRandom = &node3;

	node2._data = 2;
	node2._pNext = &node3;
	node2._pRandom = &node1;

	node3._data = 3;
	node3._pNext = &node4;
	node3._pRandom = &node3;
 
	node4._data = 4;
	node4._pNext = NULL;
	node4._pRandom = NULL;

	pHead = CopyComplexList(&node1);
}

void TestIsListCrossWithCircle()
{
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;

	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 6);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 8);
	SListBack(pHead1)->_pNext = SListFind(pHead1, 5);

	SListPushBack(&pHead2, 1);
	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 3);
	SListPushBack(&pHead2, 4);
	SListBack(pHead2)->_pNext = SListFind(pHead1, 3);

	int ret = IsListCrossWithCircle(pHead1, pHead2);
	if (1 == ret)
		printf("�������������ཻ\n");
	else if (2 == ret)
		printf("������������ཻ\n");
	else
		printf("���������ཻ\n");
}
void TestIsSListCross()
{
	//�ཻ
	//���ཻ
	PNode pHead1 = NULL;
	PNode pHead2 = NULL;
	PNode pCur;

	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 2);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 4);
	SListPushBack(&pHead1, 5);
	PrintList(pHead1);

	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 7);
	SListPushBack(&pHead2, 8);
	SListPushBack(&pHead2, 9);
	SListPushBack(&pHead2, 0);
	PrintList(pHead2);

	SListBack(pHead1->_Next) = SListFind(pHead2->_Next, 7);  //���������ཻ

	if (IsCrossWithoutCircle(pHead1, pHead2)
	{
		printf("���������ཻ\n");
			pCur = GetCrossNode(pHead1, pHead2);
			printf("����Ϊ: %d\n", pCur->_data);
	}
	else
	{
		printf("���������ཻ\n");
	}

	SListDestory(pHead1);
	SListDestory(pHead2);
}

void TestList()
{
	PNode pHead;
	SListInit(&pHead);

	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	PrintList(pHead);

	//FindMidNode(pHead);
	PNode pCur = FindMidNode(pHead);
	printf("�м�ڵ��ǣ�%d\n", pCur->_data);
	//ReverseSList(&pHead);
	PrintList(pHead);
	/*
	SListPopBack(&pHead);
	PrintList(pHead);

	SListPushFront(&pHead, 0);
	PrintList(pHead);

	SListPopFront(&pHead);
	PrintList(pHead);

	PNode pCur = NULL;
	pCur = SListFind(pHead, 3);
	if (pCur)
	{
		SListInsert(&pHead, 6, pCur);
	}
	PrintList(pHead);

	SListErease(&pHead, pCur);
	PrintList(pHead);
	*/
}
void TestSListBubbleSort()
{
	PNode pHead;
	SListInit(&pHead);

	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 3);
	PrintList(pHead);

	SListBubbleSort(pHead);
	PrintList(pHead);
	SListDestory(&pHead);
}

void TestJosephCircle()
{
	PNode pHead;
	SListInit(&pHead);

	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	PrintList(pHead);

	//����
	SListBack(pHead)->_pNext = pHead;
	JosephCircle(&pHead, 3);
	//�⻷
	pHead->_pNext = NULL;
	PrintList(pHead);
}

void TestMergeSList()
{
	PNode pHead1;
	PNode pHead2;
	SListInit(&pHead1);
	SListInit(&pHead2);

	SListPushBack(&pHead1, 1);
	SListPushBack(&pHead1, 3);
	SListPushBack(&pHead1, 5);
	SListPushBack(&pHead1, 7);
	SListPushBack(&pHead1, 9);

	SListPushBack(&pHead2, 2);
	SListPushBack(&pHead2, 4);
	SListPushBack(&pHead2, 6);
	SListPushBack(&pHead2, 8);

	PNode pNewList = MergeSList(pHead1, pHead2);
	PrintList(pNewList);
	SListDestory(&pNewList);
}
#endif 0

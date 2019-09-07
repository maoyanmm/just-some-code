#include"Seq.h"

void SeqListInit(SeqList *psl, size_t capicity)
{
	assert(psl);
	psl->_size = 0;
	psl->_capicity = capicity;
	psl->arry =(SeqList*)malloc((psl->_capicity)*sizeof(SLDataType));//动态开辟元素个数为capicity的数组
}

void SeqListDestory(SeqList *psl)
{
	assert(psl);
	psl->_size = 0;
	psl->_capicity = 0;//该函数也可以用malloc将数组重新分配为0
}

void CheckCapicity(SeqList *psl)
{
	assert(psl);
	if (psl->_size == psl->_capicity && psl->_capicity > 0)//如果存满了
	{
		psl->_capicity *= 2;
		psl->arry = (SeqList*)realloc(psl->arry,sizeof(SLDataType)*(psl->_capicity));//2倍扩展
	}
	if (psl->_capicity == 0)//如果容量为0
	{
		psl->_capicity = 5;
		psl->arry = (SeqList*)malloc(sizeof(SLDataType)*5);
	}
}

void SeqListPushbBack(SeqList *psl, SLDataType x)
{
	assert(psl);
	CheckCapicity(psl);//插入时注意要检查容量是否满了
	psl->arry[psl->_size] = x;
	psl->_size++;
}

void SeqListPopBack(SeqList *psl)
{
	assert(psl);
	CheckCapicity(psl);//删除时要注意是否容量为0
	psl->_size--;
}

void SeqListPushFront(SeqList *psl,SLDataType x)
{
	assert(psl);
	CheckCapicity(psl);
	size_t flag = psl->_size;//设置一个从后面开始的标记
	while (flag > 0)//先把所有元素从后面开始往后挪动一位
	{
		psl->arry[flag] = psl->arry[flag - 1];
		flag--;
	}
	psl->arry[0] = x;//挪动完把插入的元素放在首位，即插入成功
	psl->_size++;
}

void SeqListPopFront(SeqList *psl)
{
	assert(psl);
	CheckCapicity(psl);
	size_t start = 0;//头删只需要把第一个后面的所有元素一个个往前面挪动即可
	while (start < psl->_size-1)
	{
		psl->arry[start] = psl->arry[start + 1];
		start++;
	}
	psl->_size--;
}

void SeqListPrint(SeqList *psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->_size; i++)//注意打印的是实际存储的元素，不是capicity
	{
		printf("%d,", psl->arry[i]);
	}
}

int SeqListFind(SeqList *psl, SLDataType x)
{
	assert(psl);
	int i = 0;
	for (; i < psl->_size; i++)
	{
		if (psl->arry[i] == x)
		{
			return i;//只是查找了第一个是x的元素的下标
		}
	}
	return -1;
}

void SeqListInsert(SeqList *psl, SLDataType x, size_t pos)
{
	assert(psl);
	CheckCapicity(psl);//检查是否满了
	size_t start = psl->_size;
	while (start > pos-1) //将pos和pos后面的元素，从最后面开始向后挪动
	{
		psl->arry[start] = psl->arry[start - 1];
		start--;
	}
	psl->arry[pos - 1] = x;
	psl->_size++;
}

void SeqListErase(SeqList *psl, size_t pos)
{
	assert(psl);
	CheckCapicity(psl);
	size_t start = pos;
	while (start < psl->_size)//将pos之后的元素从pos开始不断的向前挪动
	{
		psl->arry[start-1] = psl->arry[start];
		start++;
	}
	psl->_size--;
}

void SeqListRemove(SeqList *psl, SLDataType x)
{                      //把所有是x的元素删除
	assert(psl);
	CheckCapicity(psl);
	size_t left = 0;
	size_t right = 0;
	while (right<psl->_size)//类似双指针，right向后走，把不等于x的给left，最后结果就是没有x的结果
	{
		if (x != psl->arry[right])
		{
			psl->arry[left] = psl->arry[right];
			left++;
		}
		right++;
	}
	psl->_size = left;
}

void SeqListModify(SeqList *psl, size_t pos, SLDataType x)
{
	assert(psl);
	if (pos >= psl->_size)//如果输入的位置超出的实际存储的数量，则不操作
	{
		return;
	}
	psl->arry[pos - 1] = x;
}
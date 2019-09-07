#include"Seq.h"

void SeqListInit(SeqList *psl, size_t capicity)
{
	assert(psl);
	psl->_size = 0;
	psl->_capicity = capicity;
	psl->arry =(SeqList*)malloc((psl->_capicity)*sizeof(SLDataType));//��̬����Ԫ�ظ���Ϊcapicity������
}

void SeqListDestory(SeqList *psl)
{
	assert(psl);
	psl->_size = 0;
	psl->_capicity = 0;//�ú���Ҳ������malloc���������·���Ϊ0
}

void CheckCapicity(SeqList *psl)
{
	assert(psl);
	if (psl->_size == psl->_capicity && psl->_capicity > 0)//���������
	{
		psl->_capicity *= 2;
		psl->arry = (SeqList*)realloc(psl->arry,sizeof(SLDataType)*(psl->_capicity));//2����չ
	}
	if (psl->_capicity == 0)//�������Ϊ0
	{
		psl->_capicity = 5;
		psl->arry = (SeqList*)malloc(sizeof(SLDataType)*5);
	}
}

void SeqListPushbBack(SeqList *psl, SLDataType x)
{
	assert(psl);
	CheckCapicity(psl);//����ʱע��Ҫ��������Ƿ�����
	psl->arry[psl->_size] = x;
	psl->_size++;
}

void SeqListPopBack(SeqList *psl)
{
	assert(psl);
	CheckCapicity(psl);//ɾ��ʱҪע���Ƿ�����Ϊ0
	psl->_size--;
}

void SeqListPushFront(SeqList *psl,SLDataType x)
{
	assert(psl);
	CheckCapicity(psl);
	size_t flag = psl->_size;//����һ���Ӻ��濪ʼ�ı��
	while (flag > 0)//�Ȱ�����Ԫ�شӺ��濪ʼ����Ų��һλ
	{
		psl->arry[flag] = psl->arry[flag - 1];
		flag--;
	}
	psl->arry[0] = x;//Ų����Ѳ����Ԫ�ط�����λ��������ɹ�
	psl->_size++;
}

void SeqListPopFront(SeqList *psl)
{
	assert(psl);
	CheckCapicity(psl);
	size_t start = 0;//ͷɾֻ��Ҫ�ѵ�һ�����������Ԫ��һ������ǰ��Ų������
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
	for (i = 0; i < psl->_size; i++)//ע���ӡ����ʵ�ʴ洢��Ԫ�أ�����capicity
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
			return i;//ֻ�ǲ����˵�һ����x��Ԫ�ص��±�
		}
	}
	return -1;
}

void SeqListInsert(SeqList *psl, SLDataType x, size_t pos)
{
	assert(psl);
	CheckCapicity(psl);//����Ƿ�����
	size_t start = psl->_size;
	while (start > pos-1) //��pos��pos�����Ԫ�أ�������濪ʼ���Ų��
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
	while (start < psl->_size)//��pos֮���Ԫ�ش�pos��ʼ���ϵ���ǰŲ��
	{
		psl->arry[start-1] = psl->arry[start];
		start++;
	}
	psl->_size--;
}

void SeqListRemove(SeqList *psl, SLDataType x)
{                      //��������x��Ԫ��ɾ��
	assert(psl);
	CheckCapicity(psl);
	size_t left = 0;
	size_t right = 0;
	while (right<psl->_size)//����˫ָ�룬right����ߣ��Ѳ�����x�ĸ�left�����������û��x�Ľ��
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
	if (pos >= psl->_size)//��������λ�ó�����ʵ�ʴ洢���������򲻲���
	{
		return;
	}
	psl->arry[pos - 1] = x;
}
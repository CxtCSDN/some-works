#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

void menu()
{
    printf("************************************\n");
    printf(" \\\\\\\\ <��ѡ�����¹��ܽ��в���> //// \n");
    printf("************************************\n");
    printf("************************************\n");
    printf("*** 1.β������     2.ͷ������    ***\n");
    printf("************************************\n");
    printf("*** 3.βɾ����     2.ͷɾ����    ***\n");
    printf("************************************\n");
    printf("*** 4.���ɾ��     5.�������    ***\n");
    printf("************************************\n");
    printf("*** 6.��������     7.�޸�����    ***\n");
    printf("************************************\n");
    printf("*** 8.��������     0.�˳�����    ***\n");
    printf("************************************\n");
    printf("***         9.��ӡ����           ***\n");
    printf("************************************\n");
    printf("************************************\n");
}


void InitList(SeqList* plist)
{
    plist->a = (SQDataType*)malloc(sizeof(SQDataType) * 4);
    plist->size = 0;
    plist->capacity = 4;
}


void PrintSList(const SeqList* plist)
{
    int i;
    for (i = 0; i < plist->size; i++)
        printf("%d ", plist->a[i]);
    printf("\n");
}

static void CheckCapacity(SeqList* plist)
{
    if (plist->size == plist->capacity)
    {
        SQDataType* tmp = (SQDataType*)realloc(plist->a, sizeof(SQDataType*) * plist->capacity * 2);
        assert(tmp);
        plist->a = tmp;
        plist->capacity *= 2;
    }
}

void PushBack(SeqList* plist, SQDataType x)
{
    assert(plist);
    CheckCapacity(plist);
    plist->a[plist->size] = x;
    plist->size++;
}

void PushFront(SeqList* plist, SQDataType x)
{
    assert(plist);
    CheckCapacity(plist);
    int end = plist->size - 1;
    while (end >= 0)
    {
        plist->a[end + 1] = plist->a[end];
        end--;
    }
    plist->a[0] = x;
    plist->size++;
}

void PopBack(SeqList* plist)
{
    assert(plist->size > 0);
    plist->size--;
    printf("βɾ�ɹ���\n");
}

void PopFront(SeqList* plist)
{
    assert(plist->size > 0);
    int begin = 0;
    while (begin < plist->size)
    {
        plist->a[begin] = plist->a[begin + 1];
        begin++;
    }
    plist->size--;
    printf("ͷɾ�ɹ���\n");
}

void ListModify(SeqList* plist, int pos, SQDataType x)
{
    assert(plist);
    if (plist->size == 0)
    {
        printf("��ǰ˳����������ݣ�\n");
        return;
    }
    plist->a[pos] = x;
}
void Inerst(SeqList* plist, int pos, SQDataType x)
{
    assert(plist);
    CheckCapacity(plist);
    int end = plist->size - 1;
    while (end >= pos)
    {
        plist->a[end + 1] = plist->a[end];
        end--;
    }
    plist->a[pos] = x;
    plist->size++;
    printf("����ɹ���\n");
}

int Find(const SeqList* plist, SQDataType x)
{
    assert(plist);
    if (plist->size == 0)
    {
        printf("��ǰ˳���Ϊ�գ�\n");
        return 0;
    }
    int i;
    for (i = 0; i < plist->size; i++)
    {
        if (plist->a[i] == x)
            return i;
    }
    printf("δ�ҵ������ݣ�\n");
}

void Erase(SeqList* plist, int pos)
{
    assert(plist->size > 0);
    int str = pos;
    while (str < plist->size)
    {
        plist->a[str] = plist->a[str + 1];
        str++;
    }
    plist->size--;
}
void Destroy(SeqList* plist)
{
    free(plist->a);
    plist->a = NULL;
    plist->capacity = 0;
    plist->size = 0;
}
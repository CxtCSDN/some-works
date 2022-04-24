#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
                fast++;
            }
            else
                fast++;
        }
        return slow + 1;
    }
};
#include"SeqList.h"

int main()
{
    SeqList sl;
    int enter = 0;
    InitList(&sl);
    do
    {
        menu();
        scanf("%d", &enter);
        int val;
        switch (enter)
        {
        case 1:
        {
            printf("��������Ҫβ������ݣ�\n");
            printf("����-1��Ϊ������־��\n");
            do
            {
                scanf("%d", &val);
                if (val != -1)
                    PushBack(&sl, val);
            } while (val != -1);
            printf("β��ɹ�!\n");
            break;
        }
        case 2:
        {
            printf("��������Ҫͷ������ݣ�\n");
            printf("����-1��Ϊ������־��\n");
            do
            {
                scanf("%d", &val);
                if (val != -1)
                    PushFront(&sl, val);
            } while (val != -1);
            printf("ͷ��ɹ���\n");
            break;
        }
        case 3:
            PopBack(&sl);
            break;
        case 4:
            PopFront(&sl);
            break;
        case 5:
            printf("��������Ҫ�����λ�ã�");
            int pos;
            scanf("%d", &pos);
            printf("\n");
            printf("��������Ҫ��������ݣ�");
            scanf("%d", &val);
            Inerst(&sl, pos, val);
            break;
        case 6:
        {

            printf("��������Ҫ���ҵ����ݣ�");
            scanf("%d", &val);
            int ret = Find(&sl, val);
            if (ret != 0)
                printf("�ҵ��ˣ���������˳����еĶ�Ӧ�±�Ϊ��%d", ret);
        }
        break;
        case 7:
        {

            printf("��������Ҫ�޸ĵ����ݵ��±꣺");
            int pos;
            scanf("%d", &pos);
            printf("\n");
            printf("��������Ҫ�޸ĵ����ݣ�");
            scanf("%d", &val);
            ListModify(&sl, pos, val);
            printf("�޸ĳɹ���\n");
        }
        break;
        case 8:
            printf("��ȷ��Ҫ����������\n");
            printf("������1����ȷ����0��ȡ����");
            scanf("%d", &val);
            if (val == 1)
                Destroy(&sl);
            printf("���ٳɹ���\n");
            break;
        case 9:
            PrintSList(&sl);
            break;
        case 0:
            printf("��л����ʹ�ã�ף��������죡\n");
            break;
        default:
            printf("�����������������룡\n");
            break;
        }

    } while (enter);

    return 0;
}
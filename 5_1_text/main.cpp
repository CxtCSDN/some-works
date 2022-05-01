#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* nHead = new ListNode;
        ListNode* tail = nHead;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val != val) {
                tail->next = cur;
                tail = tail->next;
            }
            cur = cur->next;
        }
        return nHead->next;
    }
};
int main()
{
    Solution s;
    ListNode head;
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(3);
    ListNode* l3 = new ListNode(5);
    head.next = l1;

    return 0;
}
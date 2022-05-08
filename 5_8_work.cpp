#define _CRT_SECURE_NO_WARNINGS 1
#include<algorithm>
 struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    
};

class Solution {
public:
    //链表是否相交
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = fast;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
    //链表的相交结点
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = new ListNode(0);
        ListNode* b = new ListNode(0);
        a = headA; b = headB;
        int lenthA = 0, lenthB = 0;
        while (a->next != nullptr) {
            a = a->next;
            lenthA++;
        }
        while (b->next != nullptr) {
            b = b->next;
            lenthB++;
        }
        if (a != b) {
            return nullptr;
        }
        else {
            a = lenthA > lenthB ? headA : headB;
            b = a == headA ? headB : headA;
            int count = std::abs(lenthA - lenthB);
            while (count--) {
                a = a->next;
            }
            while (a != b) {
                a = a->next;
                b = b->next;
            }
            return a;
        }
    }
    //链表回文
    bool chkPalindrome(ListNode* A) {
        // write code here
        if (A == nullptr || A->next == nullptr)
            return true;
        ListNode* cur = A, * pos = A;
        while (pos->next != nullptr && pos->next->next != nullptr)
        {
            cur = cur->next;
            pos = pos->next->next;
        }
        pos = cur->next;
        cur->next = nullptr;
        ListNode* tmp = nullptr;
        //将后半条链表进行逆转
        while (pos != nullptr)
        {
            tmp = pos->next;
            pos->next = cur;
            cur = pos;
            pos = tmp;
        }
        pos = A;
        tmp = cur;//保存好最后一个结点，最后可以选择复原链表
        //分别从左右两边往中间进行判断
        while (pos != nullptr && cur != nullptr)
        {
            if (pos->val != cur->val)
                return false;
            pos = pos->next;
            cur = cur->next;
        }
        return true;
    }
    //链表分割
    ListNode* partition(ListNode* pHead, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* lessTail = new ListNode(0);
        lessHead = lessTail;
        ListNode* greatHead = new ListNode(0);
        ListNode* greatTail = new ListNode(0);
        greatHead = greatTail;
        while (pHead != nullptr) {
            if (pHead->val < x) {
                lessTail->next = pHead;
                lessTail = lessTail->next;
            }
            else {
                greatTail->next = pHead;
                greatTail = greatTail->next;
            }
            pHead = pHead->next;
        }
        lessTail->next = greatHead->next;
        greatTail->next = nullptr;
        return lessHead->next;
    }
};
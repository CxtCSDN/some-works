#define _CRT_SECURE_NO_WARNINGS 1

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        //建立深拷贝结点并尾插到原节点后面
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        //设置random结点
        cur = head;
        while (cur) {
            Node* copy = cur->next;
            if (cur->random == nullptr) {
                copy->random = nullptr;
            }
            else {
                copy->random = cur->random->next;
            }
            cur = copy->next;
        }
        //将copy结点从原链表截下并尾插生成新链表
        cur = head;
        Node* newHead = new Node(0);
        Node* newTail = newHead;
        while (cur) {
            Node* copy = cur->next;
            Node* next = copy->next;
            newTail->next = copy;
            newTail = copy;
            cur->next = next;
            cur = copy->next;
        }
        return newHead->next;
    }
};
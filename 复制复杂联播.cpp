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
        //���������㲢β�嵽ԭ�ڵ����
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        //����random���
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
        //��copy����ԭ������²�β������������
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
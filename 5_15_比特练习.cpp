#define _CRT_SECURE_NO_WARNINGS 1
#include<queue>
#include<vector>

using namespace std;
class MyStack {
private:
    queue<int>* q1;
    queue<int>* q2;
public:
    MyStack() : q1(new queue<int>), q2(new queue<int>) {}

    void push(int x) {
        if (!q1->empty()) {
            q1->push(x);
        }
        else {
            q2->push(x);
        }
    }
    int pop() {
        if (q1->empty()) {
            while (q2->size() != 1) {
                q1->push(q2->front());
                q2->pop();
            }
            int ret = q2->front();
            q2->pop();
            return ret;
        }
        else {
            while (q1->size() != 1) {
                q2->push(q1->front());
                q1->pop();
            }
            int ret = q1->front();
            q1->pop();
            return ret;
        }
    }
    int top() {
        if (!q1->empty()) {
            return q1->back();
        }
        else {
            return q2->back();
        }
    }

    bool empty() {
        return q1->empty() && q2->empty();
    }
};

class MyQueue {
private:
    stack<int>* inStack;
    stack<int>* outStack;
public:
    MyQueue() : inStack(new stack<int>), outStack(new stack<int>) {}

    void push(int x) {
        inStack->push(x);
    }

    int pop() {
        if (outStack->empty() && !inStack->empty()) {
            int count = inStack->size();
            while (count--) {
                outStack->push(inStack->top());
                inStack->pop();
            }
        }
        int ret = outStack->top();
        outStack->pop();
        return ret;
    }

    int peek() {
        if (outStack->empty() && !inStack->empty()) {
            int count = inStack->size();
            while (count--) {
                outStack->push(inStack->top());
                inStack->pop();
            }
        }
        int ret = outStack->top();
        return ret;
    }

    bool empty() {
        return outStack->empty() && inStack->empty();
    }
};

class MyCircularQueue {
private:
    int* m_queue;
    int m_k;
    int m_head;
    int m_tail;
public:
    MyCircularQueue(int k) : m_queue(new int[k + 1]), m_k(k), m_head(0), m_tail(0) {}

    bool enQueue(int value) {
        if (isFull())
            return false;
        m_queue[m_tail] = value;
        m_tail++;
        if (m_tail == m_k + 1)
            m_tail = 0;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        m_head++;
        if (m_head == m_k + 1)
            m_head = 0;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return m_queue[m_head];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        int prev = m_tail - 1;
        if (m_tail == 0)
            prev = m_k;
        return m_queue[prev];
    }

    bool isEmpty() {
        return m_head == m_tail;
    }

    bool isFull() {
        int next = m_tail + 1;
        if (next == m_k + 1)
            next = 0;
        return next == m_head;
    }
};

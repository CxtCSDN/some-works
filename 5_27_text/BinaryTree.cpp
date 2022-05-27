#define _CRT_SECURE_NO_WARNINGS 1

#include"BinaryTree.h"
#include<iostream>
#include<queue>
using namespace std;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int& pi) {
    if (a[pi] == '#') {
        pi++;
        return nullptr;
    }

    BTNode* root = new BTNode(a[pi++]);
    root->_left = BinaryTreeCreate(a, pi);
    root->_right = BinaryTreeCreate(a, pi);
    return root;
}
// ����������
void BinaryTreeDestory(BTNode** root) {
    if (*root == nullptr)
        return;
    BinaryTreeDestory(&(*root)->_left);
    BinaryTreeDestory(&(*root)->_right);
    delete(*root);
    *root = nullptr;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root) {
    return root == nullptr ? 0 : BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root) {
    return root->_left == nullptr && root->_right == nullptr ? 1 : BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k) {
    if (root == nullptr)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x) {
    if (root == nullptr)
        return nullptr;
    if (root->_data == x)
        return root;
    BTNode* left = BinaryTreeFind(root->_left, x);
    BTNode* right = BinaryTreeFind(root->_right, x);
    return left == nullptr ? right : left;
}
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root) {
    if (root == nullptr)
        return;
    cout << root->_data << " ";
    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root) {
    if (root == nullptr)
        return;
    BinaryTreeInOrder(root->_left);
    cout << root->_data << " ";
    BinaryTreeInOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root) {
    if (root == nullptr)
        return;
    BinaryTreePostOrder(root->_left);
    BinaryTreePostOrder(root->_right);
    cout << root->_data << " ";
}
// �������
void BinaryTreeLevelOrder(BTNode* root) {
    queue<BTNode*> m_queue;
    m_queue.push(root);
    while (!m_queue.empty()) {
        BTNode* tmp = m_queue.front();
        cout << tmp->_data << " ";
        m_queue.pop();
        if (tmp->_left != nullptr)
            m_queue.push(tmp->_left);
        if (tmp->_right != nullptr)
            m_queue.push(tmp->_right);
    }
}
// �ж϶������Ƿ�����ȫ������
static void isTreeComplete(queue<BTNode*>& q, BTNode*& root) {
    q.push(root);
    while (!q.empty()) {
        BTNode* tmp = q.front();
        q.pop();
        if (tmp != nullptr) {
            q.push(tmp->_left);
            q.push(tmp->_right);
        }
        else
            break;
    }
}
bool BinaryTreeComplete(BTNode* root) {
    queue<BTNode*> q;
    isTreeComplete(q, root);

    while (!q.empty()) {
        BTNode* front = q.front();
        q.pop();
        if (front)
            return false;
    }
    return true;
}
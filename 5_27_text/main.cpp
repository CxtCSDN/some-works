#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include<iostream>
using namespace std;

int main()
{
	BTNode* Node1 = new BTNode('a');
	BTNode* Node2 = new BTNode('b');
	BTNode* Node3 = new BTNode('c');
	BTNode* Node4 = new BTNode('d');
	BTNode* Node5 = new BTNode('e');
	BTNode* Node6 = new BTNode('f');
	BTNode* Node7 = new BTNode('g');
	Node1->_left = Node2;
	Node1->_right = Node3;
	Node2->_left = Node4;
	Node3->_left = Node5;
	Node3->_right = Node6;
	Node2->_right = Node7;
	BTNode* find = BinaryTreeFind(Node1, 'd');
	if (find != nullptr)
		cout << find->_data << endl;
	else
		cout << "未查找到该结点" << endl;
	return 0;
}
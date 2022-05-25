#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

typedef struct BinaryTree {
public:
    BinaryTree() : val(0), left(nullptr), right(nullptr) {};
    BinaryTree(char val) : val(val), left(nullptr), right(nullptr) {}
    char val;
    struct BinaryTree* left;
    struct BinaryTree* right;
}BinaryTree;

BinaryTree* createTree(char* str, int& pi) {
    if (str[pi] == '#') {
        pi++;
        return nullptr;
    }

    BinaryTree* root = new BinaryTree(str[pi++]);
    root->left = createTree(str, pi);
    root->right = createTree(str, pi);
    return root;
}

void inOrder(BinaryTree*& root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main()
{
    char str[100];
    cin >> str;
    int pi = 0;
    BinaryTree* head = createTree(str, pi);
    inOrder(head);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<assert.h>
#include<ctype.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        else if (p->val != q->val) {
            return false;
        }
        else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};


//避免空指针
//空字符串
//前面有空白字符
//字符里掺杂字母
//转换成数字后溢出
//正负号的问题
enum Statu {
    VALID,
    INVALID
};

Statu status = INVALID;
int my_atoi(char* str) {
    assert(str);//避免空指针
    int flag = 1;
    if (*str == '\0') {
        return 0;
    }
    while (isspace(*str)) {
        str++;
    }
    if (*str == '+')
        ;
    else if (*str == '-') {
        flag = -1;
        str++;
    }
    int n = 0;
    while (*str != '\0') {
        if (isdigit(*str)) {
            n = n * 10 + flag * (*str - '0');
            if (n < INT_MIN) {
                return INT_MIN;
            }
            if (n > INT_MAX) {
                return INT_MAX;
            }
        }
        else
            break;
        str++;
    }
    if (*str == '\0')
        status = VALID;
    return n;
}
int main() {
    std::cout << (int)my_atoi((char*)"   1114555555555555") << std::endl;
    return 0;
}
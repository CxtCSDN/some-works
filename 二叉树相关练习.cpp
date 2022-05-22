#define _CRT_SECURE_NO_WARNINGS 1
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (root->left != nullptr && root->right != nullptr && root->left->val != root->right->val) {
            return false;
        }
        if (root->left != nullptr && root->right == nullptr) {
            if (root->val != root->left->val) {
                return false;
            }
        }
        if (root->left == nullptr && root->right != nullptr) {
            if (root->val != root->right->val) {
                return false;
            }
        }
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
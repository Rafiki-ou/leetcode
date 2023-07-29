#include "../common.h"

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> aux;
        if (!root) return root->val;
        int sum = 0;
        aux.push(root);
        while (!aux.empty()) {
            TreeNode* node = aux.top();
            aux.pop();
            // 对左叶子的定义是
            // 1. 它是父结点的左孩子
            // 2. 该结点是一个叶子节点
            if (node->left && !node->left->left && !node->left->right)
                sum += node->left->val;
            if (node->left) aux.push(node->left);
            if (node->right) aux.push(node->right);
        }
        return sum;
    }
};
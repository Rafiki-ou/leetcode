#include "../common.h"

#if 0
// 递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
#else
// 用层序遍历的方法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> aux;
        int res = 0;
        aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            ++res;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
            }
        }
        return res;
    }
};
#endif
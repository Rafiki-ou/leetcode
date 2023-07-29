#include "../common.h"

#if 0
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> aux;
        vector<int> res;//用来保存结果
        if (!root) return 0;
        aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            res.clear();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
                res.emplace_back(node->val);
            }
        }
        // 最后一层最左边一个值就是我们要找的值
        return res[0];
    }
};

#else

int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> aux;
        int res;//用来保存结果
        if (!root) return 0;
        aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
                // 最后一层最左边一个值就是我们要找的值
                if (i == 0) res = node->val;
            }
        }
        return res;
}

#endif
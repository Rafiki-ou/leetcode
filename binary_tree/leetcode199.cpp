#include "../common.h"

class Solution {
public:
// 二叉树的右视图
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> aux;
        if (root) aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                if (i == size - 1)
                    res.push_back(node->val);
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
            }
        }
        return res;
    }
};

#include "../common.h"

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> aux;
        if (root) aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                level.push_back(node->val);
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
            }
            res.push_back(level);
        }
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
};
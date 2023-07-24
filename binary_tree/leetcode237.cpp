#include "../common.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> aux;
        if (root) aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            double sum = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                sum += node->val;
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
            }
            res.push_back(sum / size);
        }
        return res;
    }
};
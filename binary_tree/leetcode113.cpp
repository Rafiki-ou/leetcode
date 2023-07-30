#include "../common.h"

#if 0
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        target = targetSum;
        vector<int> path;
        sumOfPath(root, path);
        return res;
    }

private:
    void sumOfPath(TreeNode* root, vector<int>& path) {
        path.push_back(root->val);
        // 找到叶子结点
        if (!root->left && !root->right) {
            int sum = 0;
            for (int val : path) sum += val;
            if (sum == target) res.push_back(path);
        }
        if (root->left) {
            sumOfPath(root->left, path);
            path.pop_back();
        }
        if (root->right) {
            sumOfPath(root->right, path);
            path.pop_back();
        }
    }

    vector<vector<int>> res;
    int target;
};
#else 


#endif
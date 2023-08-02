#include "../common.h"

lass Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums[0]);
        // 找最大值
        int index = -1;
        int max = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            index = nums[i] > max ? i : index; 
            max = nums[i] > max ? nums[i] : max;
        }
        TreeNode* root = new TreeNode(max);
        vector<int> left, right;
        // 获得左右区间值
        for (int i = 0; i < index; ++i) left.push_back(nums[i]);
        for (int i = index + 1; i < nums.size(); ++i) right.push_back(nums[i]);
        // 递归构建左右子树
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};


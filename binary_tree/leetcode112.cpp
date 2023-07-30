#include "../common.h"

#if 1
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)  return 0;
        vector<int> path;
        bool isHave = false;
        sumOfPath(root, path, isHave, targetSum);
        return isHave;
    }

private:
    void sumOfPath(TreeNode* root, vector<int>& path, bool& isHave, const int& target) {
        path.push_back(root->val);
        // 找到叶子结点
        if (!root->left && !root->right) {
            int sum = 0;
            for (int val : path) sum += val;
            isHave = sum == target; 
        }
        if (isHave) return;
        if (root->left) {
            sumOfPath(root->left, path, isHave, target);
            path.pop_back();
        }
        if (isHave) return;
        if (root->right) {
            sumOfPath(root->right, path, isHave, target);
            path.pop_back();
        }
        if (isHave) return;
    }
};
#else
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return isHave(root, targetSum - root->val);
    }

private:
    bool isHave(TreeNode* root, int curSum) {
        if (!root->left && !root->right && curSum == 0) return true;
        // 提前返回
        if (!root->left && !root->right) return false;
        if (root->left) {
            curSum -= root->left->val;
            if  (isHave(root->left, curSum)) return true;
            curSum += root->left->val; // 回溯
        }
         if (root->right) {
            curSum -= root->right->val;
            if (isHave(root->right, curSum)) return true;;
            curSum += root->right->val;
        }
        return false;
    }
};

#endif

int main()
{
    TreeNode* root = new TreeNode(1, new TreeNode(-2), new TreeNode(3));
    Solution s;
    s.hasPathSum(root, -1);
}
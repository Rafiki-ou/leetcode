#include "../common.h"

class Solution {
    // 说明：叶子节点是指没有子节点的节点。-->很重要的一点
public:
    int minDepth(TreeNode* root) {
        return getHeight(root);
    }
private:
// 采用后序遍历的方式来求高度，最下面叶子所在一层为1 然后一直往上加到root
    int getHeight(TreeNode* root) {
        // 结点为空 高度为0
        if (!root) return 0;
        // 如果有一个子树为空另一个不为空，刚看不为空的一个的高度+1(当前结点)
        if (!root->left && root->right) return 1 + getHeight(root->right);
        if (root->left && !root->right) return 1 + getHeight(root->left);
        // 都不为空的情况下 取最小高度
        return min(getHeight(root->left), getHeight(root->right)) + 1;
    }
};
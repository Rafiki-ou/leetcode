#include "../common.h"

#if 0
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(height(root->left) - height(root->right)) <= 1) return isBalanced(root->left) && isBalanced(root->right);
        return false;
    }

private:
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1; 
    }
};
#else
// 
#endif
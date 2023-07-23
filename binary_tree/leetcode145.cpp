#include "../common.h"

#if 0
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return res;
    }

private:
    vector<int> res;
    void post(TreeNode* root) {
        if (!root)  return;
        post(root->left);
        post(root->right);
        res.push_back(root->val);
    }
};
#else

#endif
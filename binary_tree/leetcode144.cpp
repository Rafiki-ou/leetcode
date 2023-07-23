#include "../common.h"

#if 0
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return res;
    }

private:
    void pre(TreeNode* root) {
        if (!root)  return;
        res.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    vector<int> res;
};
#else 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
    }

};
#endif
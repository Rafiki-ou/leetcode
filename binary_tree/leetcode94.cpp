#include "../common.h"

#if 0
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }

private:
    vector<int> res;
    void inorder(TreeNode* root) {
        if (!root)  return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};

#else 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)  return{};
        stack<TreeNode*> aux;
        vector<int> res;
        TreeNode* cur = root;
        while (!aux.empty() || cur) {
            // 一直找到最左下结点，并将路径上结点入栈
            while (cur) {
                aux.push(cur);
                cur = cur->left;
            }
            // 到了最右结点，取出栈顶，即最右下结点，访问
            cur = aux.top();
            aux.pop();
            res.push_back(cur->val);
            // 接下来访问它的右子树
            cur = cur->right;
        }
        return res;
    }
};

#endif
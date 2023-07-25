#include "../common.h" 

#if 0
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)  return root;     
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};
#else
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> aux;
        if (root) aux.push(root);
        while (!aux.empty()) {
            TreeNode* node = aux.top();
            aux.pop();
            // 中
            swap(node->right, node->left);
            // 先入栈右孩子是为了在访问的时候先访问左孩子
            if (node->right) aux.push(node->right);
            if (node->left) aux.push(node->left);
        }
            return root;
    }
};
#endif
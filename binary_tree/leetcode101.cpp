#include "../common.h"

#if 0
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return compare(root->left, root->right);
    }
private:
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right != nullptr 
        || right == nullptr && left != nullptr) 
            return false;
        else if (left == nullptr && right == nullptr)   return true;
        else if (right->val != left->val)   return false;
        else return compare(left->left, right->right) && compare(left->right, right->left);
    }
};
#else 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> aux;
        if(!root) return true;
        aux.push(root->left);
        aux.push(root->right);
        while (!aux.empty()) {
            TreeNode* left = aux.front();
            aux.pop();
            TreeNode* right = aux.front();
            aux.pop();
            if (left == nullptr && right != nullptr ||
                right == nullptr && left != nullptr)    return false;
                // 对称的位置都为空 继续比较
            else if (left == nullptr && right == nullptr)   continue;
            else if (left->val != right->val)   return false;
            aux.push(left->left);
            aux.push(right->right);
            aux.push(left->right);
            aux.push(right->left);
        }
        return true;
    }
};
#endif
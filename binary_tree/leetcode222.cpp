#include "../common.h"

#if 0
class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> aux;
        if (!root) return 0;
        aux.push(root);
        int res = 0;
        while (!aux.empty()) {
            int size = aux.size();
            res += size;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
                aux.pop();
            }
        }
        return res;
    }
};
#else
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // 对于满二叉树来说 递归遍历左树的深度等于递归遍历右树的深度
        int leftDepth = 0, rightDepth = 0;
        while (left) {
            ++leftDepth;
            left = left->left;
        }

        while (right) {
            ++rightDepth;
            right = right->right;
        }
        // 
        if (leftDepth == rightDepth) return (2 << leftDepth) - 1;
        // 对于完全二叉树 我们最终也能转换成满二叉树的情况来计算， 最后对于不满的部分直接递归计算数量得到
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
#endif

int main()
{

}
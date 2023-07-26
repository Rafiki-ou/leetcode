#include "../common.h"

// 但这个理解好像有误 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> aux;
        aux.push(root);
        while (!aux.empty()) {
            ++res;
            int size = aux.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                aux.pop();
                if (!node && i == 0) return res - 1;
                if (!node) return res;
                aux.push(node->left);
                aux.push(node->right);
            };
        }
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode* bottom = new TreeNode(5, nullptr, new TreeNode(6));
    TreeNode* level3 = new TreeNode(4, nullptr, bottom);
    TreeNode* level2 = new TreeNode(3, nullptr, level3);
    TreeNode* level1 = new TreeNode(2, nullptr, level2);
    s.minDepth(level1);
}
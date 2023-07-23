#include "../common.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root)  return{};
        stack<TreeNode*> aux;
        vector<int> res;
        aux.push(root);
        while (!aux.empty()) {
            TreeNode* cur = aux.top();
           if (cur) {
               aux.pop();
               // 如果右孩子不为空，先入栈
               if (cur->right)  aux.push(cur->right);
               aux.push(cur);
               // 当前中结点访问过了，但未处理，入栈的时候在后面加个标记
               aux.push(nullptr);
               // 如果左孩子不为空，入栈，之所以这样判断是因为nullptr被我们当作标记
               if (cur->left)   aux.push(cur->left);
           }
           else {
               aux.pop();//弹出nullptr标记，下一个就是我们需要处理的中结点，这就需要我们将其加入结果集
               cur = aux.top();
               aux.pop();
               res.push_back(cur->val);
           }
        }
        return res;
    }
};
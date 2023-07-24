#include "../common.h"
#if 0
class Solution {
public:
// 通过加标记的方法来标示每层遍历结束了
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> aux;
        vector<vector<int>> res;
        if (root)  {
            aux.push(root);
            aux.push(nullptr);
        }
        // aux.front() == nullptr说明已经遍历结束，剩下最后一个标记不需要处理
        while (!aux.empty() && aux.front()) {
            vector<int> level;
            TreeNode* node = aux.front();
            // 把队列中的每一层的遍历完，遇到了nullptr说明当前层结束了，level加入到结果集中
            while (node) {
                level.push_back(node->val);
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
                node = aux.front();
            }
            res.push_back(level);
            // 把上一层的标记出队
            aux.pop();
            // 加入这一层的标记
            aux.push(nullptr);
        }
        return res;
    }
};

#else
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> aux;
        vector<vector<int>> res;
        if (root) aux.push(root);
        while (!aux.empty()) {
            int size = aux.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = aux.front();
                level.push_back(node->val);
                aux.pop();
                if (node->left) aux.push(node->left);
                if (node->right) aux.push(node->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

#endif

int main()
{
    Solution s;
    TreeNode* node20 = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode* root = new TreeNode(3, new TreeNode(9), node20);
    s.levelOrder(root);
}
#include "../common.h"

// 遍历二叉树的叶子节点的路径
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (!root) return result;
        traversal(root, path, result);
        return result;
    }

private:
    void traversal(TreeNode* root, vector<int>& path, vector<string>& result) {
        // 需要先将当前访问的节点添加入path，因为后面的判断到叶子节点就退出了
        path.push_back(root->val);
        // 判断叶子节点-->终止条件
        // 叶子结点即没有子节点的节点
        // 到叶子节点，已经有了一条路径，添加到结果集
        if (!root->left && !root->right) {
            string res = "";
            for (int i = 0; i < path.size() - 1; ++i)
                res += to_string(path[i]) + "->";
            res += to_string(path[path.size() - 1]);
            result.push_back(res); 
        }
        
        // 对左右子树递归与回溯
        if (root->left) {
            // 递归
            traversal(root->left, path, result);
            // 回溯
            path.pop_back();
        }

        if (root->right) {
            traversal(root->right, path, result);
            // 这个回溯是直到了最后不能继续往下了才来进行回溯的，将刚访问到的节点弹出
            path.pop_back();
        }
    }
};
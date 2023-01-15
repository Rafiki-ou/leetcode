#include "../common/common.h"

/**
 * 之字形打印二叉树
*/


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        for(int i = 0; i < ret.size(); ++i)
        {
            if(i % 2 != 0)
                ret[i] = vector<int>(ret[i].rbegin(), ret[i].rend());
        }
        
        return ret;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root==NULL)
            return res;
        bool flag = true; //从左向右打印为true，从右向左打印为false
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> out;
            TreeNode* node;
            while (n>0)
            {
                if (flag) // 前取后放：从左向右打印，所以从前边取，后边放入
                {
                    node = q.front();
                    q.pop_front();
                    if (node->left)
                        q.push_back(node->left);  // 下一层顺序存放至尾
                    if (node->right)
                        q.push_back(node->right);
                }
                else  //后取前放： 从右向左，从后边取，前边放入
                {
                    node = q.back();
                    q.pop_back();
                    if (node->right)
                        q.push_front(node->right);  // 下一层逆序存放至首
                    if (node->left)
                        q.push_front(node->left);
                }
                out.push_back(node->val);
                n--;
            }
            flag = !flag;
            res.push_back(out);
        }
        return res;
    }
};

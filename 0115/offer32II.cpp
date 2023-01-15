#include "../common/common.h"

/**
 * 从上到下打印二叉树
 * url:https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cqgn1ec
*/


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
# if 0
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> _queue;
        vector<vector<int>> ans;
        if(!root)
            return ans;
        _queue.push(root);
        vector<int> oneD;
        oneD.push_back(root->val);
        // 当前层个数
        int num = 1;
        // 下一层最多可有的个数
        int nextLevelNum = 2;
        while(!_queue.empty())
        {
            // 存取每层
            vector<int> oneD;
            // 连续取出同一层的节点
            for(int i = 0; i < num && !_queue.empty(); ++i)
            {
                TreeNode * front = _queue.front();
                // 如果队头元素有左右孩子，刚将左右孩子加入队列，否则，下一层的个数-1
                if(front->left) 
                    _queue.push(front->left);
                else 
                    --nextLevelNum;
                if(front->right)
                    _queue.push(front->right);
                else
                    --nextLevelNum;
                oneD.push_back(front->val);
                _queue.pop();
            }
            // 遍历完当前层之后，更新下一层要遍历的个数
            num = nextLevelNum;
            nextLevelNum = 2*_queue.size();
            ans.push_back(oneD);
        }      
        return ans;
    }
};

#endif

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
        
        return ret;
    }
};


int main()
{
    Solution s;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    n4->left = n5;
    n3->left = n4;
    n2->left = n3;
    n1->left = n2;

    vector<vector<int>> v = s.levelOrder(n1);
    cout << endl;
}
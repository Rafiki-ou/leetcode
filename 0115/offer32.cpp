#include "../common/common.h"

/**
 * 从上到下打印二叉树
 * url:https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cqgn1ec
*/


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        queue<TreeNode*> _queue;
        vector<int> ans;
        if(!root)
            return ans;
        _queue.push(root);
        while(!_queue.empty())
        {
            TreeNode * front = _queue.front();
            ans.push_back(front->val);
            if(front->left)
                _queue.push(front->left);
            if(front->right)
                _queue.push(front->right);
            _queue.pop();
        }
        return ans;
    }
};

int main()
{
    Solution s;
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(20);
    TreeNode* n4 = new TreeNode(15);
    TreeNode* n5 = new TreeNode(7);
    n3->left = n4;
    n3->right = n5;
    n1->left = n2;
    n1->right = n3;

    vector<int> v = s.levelOrder(n1);
    cout << endl;
}
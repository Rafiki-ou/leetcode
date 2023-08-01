#include "../common.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        if (preorder.size() == 1) return new TreeNode(preorder[0]);
        TreeNode* root = new TreeNode(preorder[0]);
        int rootVal = preorder[0];
        vector<int> leftInorder, rightInorder;
        int index = 0;
        for (; index < inorder.size(); ++index) {
            if (inorder[index] == rootVal)  break;
            leftInorder.push_back(inorder[index]);
        }
        for (int i = index+1; i < inorder.size(); ++i)
            rightInorder.push_back(inorder[i]);
        
        vector<int> leftPreorder, rightPreorder;
        for(int i = 1; i <= leftInorder.size(); ++i) {
            leftPreorder.push_back(preorder[i]);
        }

        for (int i = leftInorder.size() + 1; i < preorder.size(); ++i) {
            rightPreorder.push_back(preorder[i]);
        }

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
int main()
{
    Solution s;
    vector<int> inorder{9,3,15,20,7};
     vector<int> preorder{3,9,20,15,7};
    s.buildTree(preorder, inorder);
}
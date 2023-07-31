#include "../common.h"

#if 1
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return nullptr;
        if (postorder.size() == 1) return new TreeNode(postorder[0]);
        // 后序遍历的最后一个节点一定是根节点 左 右 中
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        // 然后根据这个中节点去切中序遍历  左 中 右得到左中序 和右中序
        vector<int> leftInorder, rightInorder;
        int rootVal = postorder[postorder.size() - 1];
        int index = 0;
        // 切左中序
        for (; index < inorder.size(); ++index) {
            if (inorder[index] == rootVal) break;
            leftInorder.push_back(inorder[index]);
        }
        // 右中序
        for (int i = index + 1; i < inorder.size(); ++i) {
            rightInorder.push_back(inorder[i]);
        }
        vector<int> leftPostorder, rightPostorder;
        // 利用左中序去切左后序，因为知道了左中序，便可以知道后序遍历中的左区间
        for (int i = 0; i < index; ++i) {
            leftPostorder.push_back(postorder[i]);
        }
        // 右后序
        for (int i = index; i < postorder.size() - 1; ++i) {
            rightPostorder.push_back(postorder[i]);
        }
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);
        return root;
    }
};
#else

#endif

int main()
{
    vector<int> inorder {9, 3, 15, 20, 7};
    vector<int> postOrder {9, 15, 7, 20, 3};
    Solution s;
    s.buildTree(inorder, postOrder);
}
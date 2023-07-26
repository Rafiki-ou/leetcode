#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <deque>
#include <queue>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() 
        :val(0), left(nullptr), right(nullptr) 
        {}
    TreeNode(int val)
        :val(val), left(nullptr), right(nullptr)
        {}

    TreeNode(int val, TreeNode* left, TreeNode* right)
        :val(val), left(left), right(right)
        {}
};

 
 class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
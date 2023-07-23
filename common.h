#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <deque>

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

 
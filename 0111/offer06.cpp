#include "../common/common.h"

/**
 * 从尾到头打印链表
*/



  //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
      vector<int> v;
      while(head)
      {
        v.push_back(head->val);
        head = head->next;
      }  
      return vector<int>(v.rbegin(), v.rend());
    }
};

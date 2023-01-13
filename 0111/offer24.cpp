#include "../common/common.h"

/**
 * 反转链表
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
/**
  迭代方法
     ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* cur = head;
            while (cur)
            {
                ListNode*node = cur->next;
                cur->next = prev;
                prev = cur;
                cur = node;
            }
            return prev;
    }
*/

    // 递归
    ListNode* reverseList(ListNode* head) {
          return recur(head, nullptr);
    }

private:
    ListNode* recur(ListNode* cur, ListNode* prev)
    {
        if(cur == nullptr)  //终止条件
            return prev;
        ListNode* ret = recur(cur->next, cur);// 递归后继节点
        cur->next = prev;
        return ret;
    }
};

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    Solution s;
    s.reverseList(l1);
}
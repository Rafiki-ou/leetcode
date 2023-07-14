#if 0
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
       ListNode* virtualHead = new ListNode(0); // 虚头
       virtualHead->next = head;
       ListNode* cur = virtualHead;
       while(cur->next && cur->next->next) {
           // 临时保存当前结点后面的两个结点
           ListNode* p1 = cur->next;
           ListNode* p2 = cur->next->next;
           // 交换两个结点
           cur->next = p2;
           p1->next = p2->next;
           p2->next = p1;
           // 指针后移两位
           cur = cur->next->next;
       }
       return virtualHead->next;
    }
};
#else
#endif
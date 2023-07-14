#include "../common.h"


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针，最终慢指针指向的位置就是待删除的位置
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(n--) fast = fast->next;
        while(fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // 判断待删除位置是不是头结点
        if(slow == head)    return head->next;
        prev->next = slow->next;
        return head;
    }
};

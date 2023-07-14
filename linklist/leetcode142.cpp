#include "../common.h"
#if 0
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        // 关于为什么要判断fast->next != nullptr是因为，fast一次走两步，避免在做fast=fast->next->next的时候不造成内存访问错误
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // 两者相遇，代表有环，开始找入口
            if(slow == fast) {
                // 我们让其中一个指针指向起始处，一个指向相遇处，每次走一个结点，相遇处就是入口
                slow = head;
                //两指针每次走一步，最终会在入口处再次相遇
                while(slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
#else
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // 环内相遇
            if (slow == fast) {
                ListNode* index = head;
                while (index != slow) {
                    index = index->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
#endif
#include "../common.h"

#if 0
// 辅助栈
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA, *curB = headB;
        if (!curA || !curB) return nullptr;
        stack<ListNode*> a_stack, b_stack;
        while (curA) {
            a_stack.push(curA);
            curA = curA->next;
        }

        while (curB) {
            b_stack.push(curB);
            curB = curB->next;
        }

        while (!a_stack.empty() && !b_stack.empty()) {
            if ( a_stack.top() == b_stack.top() && curA == curB) {
                curA = a_stack.top(); a_stack.pop();
                curB = b_stack.top(); b_stack.pop();
            }
            else 
                return curA;
        }
        return curA;
    }
};
#else 
// 双指针法
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA, *curB = headB;
        int lenA = 0, lenB = 0;
        while (curA) {
            ++lenA;
            curA = curA->next;
        }

        while (curB) {
            ++lenB;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;
        // 保证a长于b
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }
        lenA -= lenB;
        while (lenA--)
            curA = curA->next;
        while (curA && curB) {
            if (curA == curB)   break;
            curA = curA->next;
            curB = curB->next;
        }

        return curA == curB ? curA : nullptr;
    }
};
#endif
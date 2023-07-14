#include "../common.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(0),next(nullptr){}
    ListNode(int val) :val(val), next(nullptr) {}
    ListNode(int val, ListNode* pNext) :val(val), next(pNext) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 如果待删除节点在前面
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 待删除节点不在前面
        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else 
                cur = cur->next;
        }
        return head;
    }
};


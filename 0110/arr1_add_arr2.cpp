/**
 * 两个非空链表相加，按照逆序方式存储
*/
#include "../common/common.h"
 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    /*ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1;
        while (l1)
        {
            s1+= 48+ l1->val;
            l1=l1->next;
        }

        string s2;
        while (l2)
        {
            s2+= 48+l2->val;
            l2=l2->next;
        }

        s1 = string(s1.rbegin(), s1.rend());
        s2 = string(s2.rbegin(), s2.rend());

        int v1 = atoi(s1.c_str());
        int v2 = atoi(s2.c_str());

        int sum = v1 + v2;
        char arr[32];
        //itoa(sum, arr, 10);
        sprintf(arr,"%d",sum);
        string s3(arr);
        ListNode* node = new ListNode(s3.at(0) - 48);
        for(int i = 1; i < s3.size(); ++i)
        {
            ListNode *tmp = new ListNode(s3.at(i) - 48);
            tmp->next = node;
            node = tmp;
        }

        return node;
    }*/

 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    //head的存在是使头指针的位置不变，而使用tail去变化
    ListNode* head = nullptr, *tail = nullptr;
    while(l1||l2)
    {
        // 短的一个链表后面的值默认为0,这不影响最终结果
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = v1 + v2 + carry;
        if(!head)
        {
            head = tail = new ListNode(sum%10);
        }
        else
        {
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        carry = sum / 10;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
        
    }
    if(carry > 0)
    {
        tail->next = new ListNode(carry);
    }
 }
};


int main()
{
    ListNode* l1 = new ListNode(3);
    ListNode* l11 = new ListNode(4);
    ListNode* l111 = new ListNode(2);
    l11->next = l1;
    l111->next = l11;
    ListNode* l2 = new ListNode(4);
    ListNode* l22 = new ListNode(6);
    ListNode* l222 = new ListNode(5);
    l22->next = l2;
    l222->next = l22;

    Solution s;
    ListNode* l3 =  s.addTwoNumbers(l111,l222);
    cout << endl;
}

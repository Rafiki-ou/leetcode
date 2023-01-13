#include "../common/common.h"

/**
 * 复杂链表的复制
 * 请实现 copyRandomList 函数，
 * 复制一个复杂链表。在复杂链表中，
 * 每个节点除了有一个 next 指针指向下一个节点，
 * 还有一个 random 指针指向链表中的任意节点或者 null
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
// 方法一
   /* Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        Node* _head = new Node(head->val);
        Node* newHead = _head;
        Node* oldHead = head;
        // 第一次遍历，复制全部的结点，只完成next和val的复制
        while(oldHead->next != nullptr)
        {
            // 根据原来的链表来新创建一个新的节点，然后挂载到新的链表上
            Node* next = new Node(oldHead->next->val);
            newHead->next = next;
            // 指针后移
            oldHead = oldHead->next;
            newHead = newHead->next;
        }
        // _head是复制得到的一个新的链表，只保存有next和val的关系，random还未复制
        Node* newRandomHead = _head;
        Node* oldRandomHead = head;
        // 第二次遍历
        while(oldRandomHead != nullptr)
        {
            // 这是根据原来链表上挂载的随机节点创建一个新的随机节点
            Node* randomNode = oldRandomHead->random;
            // 随机节点为nullptr的话就不用理会，因为默认的就是nullptr
            if(randomNode)
            {
                Node* temp = head;
                Node* newTemp = _head;
                // 再次遍历原来的链表，去找到当前节点所指向的那个随机节点
                while(temp != randomNode)
                {
                    temp = temp->next;
                    newTemp = newTemp->next;
                }
                // 找到了那个新链表上的随机节点
                newRandomHead->random = newTemp;
            }
            // 移动新旧链表
            oldRandomHead = oldRandomHead->next;
            newRandomHead = newRandomHead->next;
        }
        return _head;
    }
    */

// 方法二
    Node* copyRandomList(Node* head)
    {
        if(!head)   return nullptr;
        Node* cur = head;
        unordered_map<Node*,Node*> map;
        // 复制各节点并建立新旧节点的映射关系
        while(cur)
        {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }

        cur = head;
        
        // 构建新链表的next和random的指向
        while(cur)
        {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        // 返回新链表的头节点
        return map[head];
    }
};

int main()
{
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    Solution s;
    s.copyRandomList(n1);
}
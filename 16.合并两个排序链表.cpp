//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

#include <iostream>
using namespace std;

struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr)
        {
            return pHead2;
        }
        if (pHead2 == nullptr)
        {
            return pHead1;
        }
        ListNode* p1 = pHead1, *p2 = pHead2;
        ListNode* newHead = nullptr;
        //选取值小的作为头结点
        if (pHead1->val <= pHead2->val)
        {
            newHead = pHead1;
            p1 = p1->next;
        }
        else
        {
            newHead = pHead2;
            p2 = p2->next;
        }
        ListNode* cur = newHead; //记录头节点
        while (p1 != nullptr && p2 != nullptr)
        {
            if(p1->val <= p2->val)
            {
                cur->next = p1;
                p1 = p1->next;
            }
            else
            {
                cur->next = p2;
                p2 = p2->next;
            }

            cur = cur->next;
            
        }

        if (p1 != nullptr)
        {
            cur->next = p1;
        }
        else if(p2 != nullptr)
        {
            cur->next = p2;
        }
        else
        {
            cur->next = nullptr;
        }

        return newHead;
    }
};
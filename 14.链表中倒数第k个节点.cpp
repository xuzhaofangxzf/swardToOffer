//输入一个链表，输出该链表中倒数第k个结点。

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k <= 0)
        {
            return nullptr;
        }
        ListNode* fast = pListHead;
        ListNode* cur = pListHead;
        
        while(k--)
        {
            if (fast != nullptr)
            {
                fast = fast->next;
            }
            else
            {
                return nullptr; //长度不足k
            }
            
        }

        while(fast != nullptr)
        {
            cur = cur->next;
            fast = fast->next;
        }
        return cur;
    }
};
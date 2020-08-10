//翻转链表
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
    //头插法
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* cur = pHead->next;
        pHead->next = nullptr;
        ListNode* next;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pHead;
            pHead = cur;
            cur = next;
        }
        return pHead;
    }

    //三指针
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode* pre = nullptr; //pre初始值为nullptr
        ListNode* cur = pHead; // 当前节点为头结点
        ListNode* next = nullptr; //下一个节点 为了保存链表后续内容
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

};
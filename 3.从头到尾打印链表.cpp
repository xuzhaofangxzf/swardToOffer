/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

/*先翻转链表，然后按顺序读入*/
#include <iostream>
#include <vector>
#include <stack>
struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};
using namespace std;


class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* newhead = reverseList(head);
        vector<int> res;
        while (newhead != nullptr)
        {
            res.push_back(newhead->val);
            newhead = newhead->next;
        }
        return res;
    }

private:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode* cur = head->next;
        head->next = nullptr;
        ListNode* next;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }
        return head;
    }

public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        while (head != nullptr)
        {
            s.push(head->val);
            head = head->next;
        }
        vector<int> res;
        while (!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }

        return res;
    }
};

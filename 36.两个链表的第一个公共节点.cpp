/*
输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

*/
struct ListNode {
      int val;
      struct ListNode *next;
      ListNode(int x) :
            val(x), next(NULL) {
      }
};


class Solution {
public:
    //分别求出两个链表的长度，让后根据长度差d，利用快慢指针，快指针先走d步，然后快慢指针逐个比对
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if( !pHead1 || !pHead2) return nullptr;
        //if(pHead1 == pHead2) return pHead1;
        int l1 = 0, l2 = 0;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (p1)
        {
            l1++;
            p1 = p1->next;
        }
        while (p2)
        {
            l2++;
            p2 = p2->next;
        }
        p1 = pHead1;
        p2 = pHead2;
        if (l1 > l2)
        {
            int k = l1 - l2;
            while (k > 0)
            {
                p1 = p1->next;
                k--;
            }
            while (p1 && p2)
            {
                if (p1 == p2)
                {
                    return p1;
                }
                else
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }
        }
        else
        {
            int k = l2 - l1;
            while (k > 0)
            {
                p2 = p2->next;
                k--;
            }
            while (p1 && p2)
            {
                if (p1 == p2)
                {
                    return p1;
                }
                else
                {
                    p1 = p1->next;
                    p2 = p2->next;
                }
            }           
        }
        return nullptr;
    }
};
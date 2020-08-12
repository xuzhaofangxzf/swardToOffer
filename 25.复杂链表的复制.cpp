//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），请对此链表进行深拷贝，并返回拷贝后的头结点。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

#include <iostream>
#include <unordered_map>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    //分两步, 第一步,建立与旧的链表对应的新节点,用hash_map保存起来
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
        {
            return nullptr;
        }
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode* cur = pHead;
        while (cur != nullptr)
        {
            map[cur] = new RandomListNode(cur->label);
            cur = cur->next;
        }
        //第二步:复制连接关系
        cur = pHead;
        while (cur)
        {
            map[cur]->next = (cur->next == nullptr) ? nullptr : map[cur->next]; //新节点->next指向旧的next节点对应的节点
            map[cur]->random = (cur->random == nullptr) ? nullptr : map[cur->random];
            cur = cur->next;
        }
        return map[pHead];
        
    }

    //方法2:不借用map,多次遍历链表
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
        {
            return nullptr;
        }
        //第一步: 在旧的链表中创建新的节点,放到旧的链表后面,此时不处理next及random节点
        RandomListNode * cur = pHead;
        while (cur)
        {
            RandomListNode* next = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = next;
            cur = next;
        }
        //第二部:根据旧的链表的next节点及random节点,重新赋值给新的链表,建立关系
        cur = pHead;
        while (cur)
        {
            cur->next->random = (cur->random == nullptr) ? nullptr : cur->random->next;
            cur = cur->next->next;
        }
        //第三部: 将新的链表从旧的链表中断开
        cur = pHead;
        RandomListNode* newHead = cur->next;
        while (cur)
        {
            RandomListNode* cloneNode = cur->next; 
            cur->next = cloneNode->next; //在未断开之前,如果cur!=nullptr,则cur->next不可能是nullptr
            cloneNode->next = (cloneNode->next == nullptr) ? nullptr : cloneNode->next->next;
            cur = cur->next;
        }
        return newHead;
    }
};
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //中序遍历,创建循环链表
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return nullptr;
        stack<TreeNode*> s;
        TreeNode* cur = pRootOfTree;
        TreeNode* pre = nullptr;
        TreeNode* pHead = nullptr;
        while (cur != nullptr || !s.empty())
        {
            while (cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            
            if (!s.empty())
            {
                cur = s.top();
                cur->left = pre;
                if (pre != nullptr)
                {
                    pre->right = cur;
                }
                else
                {
                    pHead = cur;
                }
                pre = cur;
                s.pop();
                cur = cur->right;
            }
        }
        pre->right = pHead;
        pHead->left = pre;
        return pHead;
    }
    //递归版本
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return nullptr;

        Convert(pRootOfTree->left);
        TreeNode* cur = pRootOfTree;
        cur->left = pre;
        if (pre)
        {
            pre->right = cur;
        }
        else
        {
            pHead = cur;
        }
        pre = cur;
        Convert(pRootOfTree->right);
        return pHead;

    }
    #if 0
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (!pRootOfTree) return nullptr;
        TreeNode* pre, * pHead;
        return Convert(pRootOfTree, pre, pHead);
    }
    TreeNode* Convert(TreeNode* pRootOfTree, TreeNode*& pre, TreeNode*& pHead)
    {
        Convert(pRootOfTree->left, pre, pHead);
        TreeNode* cur = pRootOfTree;
        cur->left = pre;
        if (pre)
        {
            pre->right = cur;
        }
        else
        {
            pHead = cur;
        }
        pre = cur;
        Convert(pRootOfTree->right, pre, pHead);
        return pHead;
    }
    #endif
private:
    TreeNode* pre = nullptr;
    TreeNode* pHead = nullptr;
};
//二叉树的深度
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    //方法1: 递归
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        int ldepth = TreeDepth(pRoot->left);
        int rdepth = TreeDepth(pRoot->right);
        return max(ldepth, rdepth) + 1;
    }

    //方法2: 非递归    
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        int level = 0;
        queue<TreeNode*> q;
        q.push(pRoot);
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            level++;
        }
        return level;
    }

};
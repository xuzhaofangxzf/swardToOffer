//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
// 在这里，我们只需要考虑其平衡性，不需要考虑其是不是排序二叉树
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot) return true;
        int ldepth = GetDepth(pRoot->left);
        int rdepth = GetDepth(pRoot->right);
        return (abs(ldepth - rdepth) <= 1) && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    //求深度
    int GetDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        int ldepth = GetDepth(pRoot->left);
        int rdepth = GetDepth(pRoot->right);
        return max(ldepth, rdepth) + 1;
    }


    //方法2 用一个哈希表将树的深度保存下来
    int GetDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        if (map.find(pRoot) != map.end())
        {
            return map[pRoot];
        }
        int ldepth = GetDepth(pRoot->left);
        int rdepth = GetDepth(pRoot->right);
        map[pRoot] = max(ldepth, rdepth) + 1;
        return map[pRoot];
    }
    bool judge(TreeNode* pRoot)
    {
        if(!pRoot) return true;
        return (abs(map[pRoot->left] - map[pRoot->right]) <= 1) && judge(pRoot->left) && judge(pRoot->right);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        GetDepth(pRoot);
        return judge(pRoot);
    }

private:
    unordered_map<TreeNode*, int> map;

    //方法3 在求树的深度的同时,直接判断即可
    int GetDepth(TreeNode* pRoot)
    {
        if (!pRoot) return 0;
        int ldepth = GetDepth(pRoot->left);
        if (ldepth == -1) return -1;
        int rdepth = GetDepth(pRoot->right);
        if (rdepth == -1) return -1;
        if (abs(rdepth - ldepth) > 1) return -1;
        return max(ldepth, rdepth) + 1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        //if (!pRoot) return true;
        return GetDepth(pRoot) != -1;
    }
};
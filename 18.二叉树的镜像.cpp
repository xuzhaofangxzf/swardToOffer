//操作给定的二叉树，将其变换为源二叉树的镜像。


#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot) return;

        pRoot = DfsMirror(pRoot);
    }
private:
    //只能先遍历左右,再遍历根节点.
    TreeNode* DfsMirror(TreeNode* pRoot)
    {
        if (!pRoot) return nullptr;
        TreeNode* left = DfsMirror(pRoot->left);
        TreeNode* right = DfsMirror(pRoot->right);
        pRoot->left = right;
        pRoot->right = left;
        return pRoot;
    }
};
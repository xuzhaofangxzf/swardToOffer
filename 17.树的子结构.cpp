//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2) return false;
        //遍历树的根,左,右,pRoot2是否与其有相同的结构
        return (isSubtree(pRoot1, pRoot2) || isSubtree(pRoot1->left, pRoot2) || isSubtree(pRoot1->right, pRoot2));
    }
private:
    //辅助函数,判断两个树的结构是否一样
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2) return true; //此时pRoot2为空与题意的pRoot2为空不是一样的,此时代表pRoot2递归后,可能是某个节点已经为空了,此为递归终止条件
        if (!pRoot1) return false;
        return ((pRoot1->val == pRoot2->val) && isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right));
    }
};
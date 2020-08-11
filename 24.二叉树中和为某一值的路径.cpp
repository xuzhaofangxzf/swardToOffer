
//输入一颗二叉树的根节点和一个整数，按字典序打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
递归算法三部曲：

明白递归函数的功能：FindPath(TreeNode* root,int sum)，从root节点出发，找和为sum的路径
递归终止条件：当root节点为叶子节点并且sum==root->val, 表示找到了一条符合条件的路径
下一次递归：如果左子树不空，递归左子树FindPath(root->left, sum - root->val),如果右子树不空，递归右子树，FindPath(root->right, sum - root->val)
*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if (!root) return vector<vector<int> >(0, vector<int>(0));
        vector<vector<int>> res;
        vector<int> path;
        preOrderDFS(root, path, res, expectNumber);
        return res;
    }

private:
    void preOrderDFS(TreeNode* root, vector<int> &path, vector<vector<int> > &res, int expectNumber)
    {
        if (!root) return;
        path.push_back(root->val);
        if (root->val == expectNumber && !root->left && !root->right) //根的值与目标值相等且为叶子节点
        {
            res.push_back(path);
        }

        preOrderDFS(root->left, path, res, expectNumber - root->val);
        preOrderDFS(root->right, path, res, expectNumber - root->val);
        path.pop_back(); // 代码走到这里，表明左右都已经遍历到叶子节点,不管之前是不是都已经满足条件,都要回溯，当前path中最后的节点已经不需要了
    }
};
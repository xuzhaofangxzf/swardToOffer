/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
/*前序遍历中，第一个数字是根节点，通过中序遍历，找到根节点对应的位置，则该位置的左边为左子树，右边为右子树，用递归的方式重建左子树，右子树。重载同名函数，分别增加左右子树的边界*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        return reConstructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size());
    }

private:

    TreeNode* reConstructBinaryTree(vector<int> pre, int pre_l, int pre_r, vector<int> vin, int vin_l, int vin_r) {
        if (pre_l > pre_r)
        {
            return nullptr;
        }
        int rootval = pre[pre_l];
        TreeNode* root = new TreeNode(rootval);
        for (int i = vin_l; i <= vin_r; i++)
        {
            if (rootval == vin[i])
            {
                root->left = reConstructBinaryTree(pre, pre_l + 1, pre_l + (i - vin_l), vin, vin_l, i - 1);
                root->right = reConstructBinaryTree(pre, pre_l + (i - vin_l) + 1, pre_r, vin, i + 1, vin_r);
                break;
            }
        }
        return root;
    }
};
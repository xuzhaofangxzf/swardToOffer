//从上往下打印出二叉树的每个节点，同层节点从左至右打印。

#include <iostream>
#include <vector>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root) return vector<int>(0);
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            res.push_back(cur->val);
            q.pop();
            if(cur->left)
            {
                q.push(cur->left);
            }
            if (cur->right)
            {
                q.push(cur->right);
            }
        }

        return res;
    }
};
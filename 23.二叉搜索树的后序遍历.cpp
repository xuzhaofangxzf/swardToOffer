//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
#include <iostream>
#include <vector>
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
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0 || sequence.empty()) return false;
        return isBST(sequence, 0, sequence.size() - 1);
    }
private:
    bool isBST(vector<int> &sequence, int left, int right)
    {
        if (left >= right) return true;
        int i = left;
        while (i < right && sequence[i] < sequence[right]) //找到左右子树的分界点
        {
            i++;
        }
        for (int j = i; j < right; j++)
        {
            if (sequence[j] < sequence[right])
            {
                return false;
            }
        }
        return isBST(sequence, left, i - 1) && isBST(sequence, i, right - 1);
    }
};
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
    首先设定上下左右边界
    其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
    判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
    若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
    不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案

*/
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return vector<int>(0);
        vector<int> res;
        res.reserve(matrix.size() * matrix[0].size());
        //定义上下左右边界,up,down为行, left,right为列
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() -1;
        while (true)
        {
            for (int i = left; i <= right; i++)
            {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;
            for (int i = up; i<= down; i++)
            {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) break;
            for (int i = right; i >= left; i--)
            {
                res.push_back(matrix[down][i]);
            }
            if(--down < up) break;

            for (int i = down; i>= up; i--)
            {
                res.push_back(matrix[i][left]);
            }
            if(++left > right) break;
        }

        return res;
    }
};

